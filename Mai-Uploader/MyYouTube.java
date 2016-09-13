import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

import com.google.api.client.auth.oauth2.Credential;
import com.google.api.client.extensions.java6.auth.oauth2.AuthorizationCodeInstalledApp;
import com.google.api.client.extensions.jetty.auth.oauth2.LocalServerReceiver;
import com.google.api.client.googleapis.auth.oauth2.GoogleAuthorizationCodeFlow;
import com.google.api.client.googleapis.auth.oauth2.GoogleClientSecrets;
import com.google.api.client.googleapis.json.GoogleJsonResponseException;
import com.google.api.client.googleapis.media.MediaHttpUploader;
import com.google.api.client.http.HttpTransport;
import com.google.api.client.http.InputStreamContent;
import com.google.api.client.http.javanet.NetHttpTransport;
import com.google.api.client.json.JsonFactory;
import com.google.api.client.json.jackson2.JacksonFactory;
import com.google.api.client.util.store.FileDataStoreFactory;
import com.google.api.services.youtube.YouTube;
import com.google.api.services.youtube.model.Video;
import com.google.api.services.youtube.model.VideoSnippet;
import com.google.api.services.youtube.model.VideoStatus;
import com.google.common.collect.Lists;

public class MyYouTube implements Runnable{
	/** HTTP�ʐM�̃C���X�^���X */
	private static final HttpTransport HTTP_TRANSPORT = new NetHttpTransport();
	
	/** JS���������߂̃C���X�^���X�@Global instance of the JSON factory. */
	private static final JsonFactory JSON_FACTORY = new JacksonFactory();

	/** ���N�G�X�g�����C���X�^���X */
	private static YouTube youtube;

	/* Global instance of the format used for the video being uploaded (MIME type). */
	private static String VIDEO_FILE_FORMAT = "video/*";
	
	private File uploadedFile;
	
	private Video videoObjectDefiningMetadata;
	
	MyYouTube() throws Exception{
		//"https://www.googleapis.com/auth/youtube.upload"��scopes�ɓ���Ă���
		List<String> scopes = Lists.newArrayList("https://www.googleapis.com/auth/youtube.upload");
		try {
		      // �ؖ���
		      Credential credential = authorize(scopes);
		      
		      // youtube�I�u�W�F�N�g�͂��ׂĂ�api���N�G�X�g���쐬����
		      youtube = new YouTube.Builder(HTTP_TRANSPORT, JSON_FACTORY, credential).setApplicationName(
		          "Mai_Uploader").build();
		} catch (GoogleJsonResponseException e) {
			System.err.println("GoogleJsonResponseException code: " + e.getDetails().getCode() + " : "
					+ e.getDetails().getMessage());
			e.printStackTrace();
		}
	}
	
	/**
	 * Authorizes the installed application to access user's protected data.
	 *
	 * @param scopes youtube�̃A�b�v���[�h�ɕK�v��scope�̃��X�g
	 */
	private static Credential authorize(List<String> scopes) throws Exception {

		// client_secrets.json��ǂݍ���
		GoogleClientSecrets clientSecrets = GoogleClientSecrets.load(
	    	JSON_FACTORY, new FileReader("client_secrets.json"));
	    
	    // �t�@�C���������������ĂȂ����`�F�b�N�@Checks that the defaults have been replaced (Default = "Enter X here").
	    if (clientSecrets.getDetails().getClientId().startsWith("Enter")
	        || clientSecrets.getDetails().getClientSecret().startsWith("Enter ")) {
	    	System.out.println(
	    		"Enter Client ID and Secret from https://code.google.com/apis/console/?api=youtube"
	    			+ "into youtube-cmdline-uploadvideo-sample/src/main/resources/client_secrets.json");
	    	System.exit(1);
	    }
	    
	    // �ؖ����𔭍s�@Set up file credential store.
	    FileDataStoreFactory fdsf = new FileDataStoreFactory(
	    		new File(/*System.getProperty("user.home"), ".credentials/youtube-api-uploadvideo.json"*/".\\credentials\\"));
	    
	    // �F�؃R�[�h�̗����ݒ肵�܂��@Set up authorization code flow.
	    GoogleAuthorizationCodeFlow flow = new GoogleAuthorizationCodeFlow.Builder(
	        HTTP_TRANSPORT, JSON_FACTORY, clientSecrets, scopes).setDataStoreFactory(fdsf)
	        .build();

	    // ���[�J���T�[�o�[�𗧂Ă�9000�̃|�[�g�Ƀo�C���h Build the local server and bind it to port 9000
	    LocalServerReceiver localReceiver = new LocalServerReceiver.Builder().setPort(8080).build();

	    // �F��
	    //.authorize()�̈����ɂ͉������ꂽ�炢���H
	    return new AuthorizationCodeInstalledApp(flow, localReceiver).authorize("maikagami2016@gmail.com");
	}
	
	/*
	 * ����ɏ���t������
	 * 	file         -�A�b�v���[�h���铮��t�@�C���̏ꏊ
	 * 	title        -����̃^�C�g���@�f�t�H���g��"Test title"
	 * 	description  -����ɂ�������@�f�t�H���g��"Test description"
	 * 	category     -����Ɋ֘A����J�e�S��id 	�f�t�H���g��"22"
	 * 	keywords     -����Ɋ֘A����L�[���[�h���R���}�ŋ�؂������X�g ����͊֌W�Ȃ�
	 *  privateStatus-����̃v���C�o�V�\�X�e�[�^�X public(���J),private(����J),unlisted(������J)���L���l�@�����unlisted���g�p
	 */
	
	//�A�b�v���[�h���铮����Z�b�g����
	public boolean setVideo(File file) {
		if(isMp4(file)){ return false; }
		uploadedFile = file;
		return true;
	}
	
	//�t�@�C����mp4�t�@�C�����`�F�b�N����
	public boolean isMp4(File file){
		return file.isFile() && file.canRead() && file.getPath().endsWith(".avi");
	}
	
		
	public void setMetadata(
			String title, String description){
		this.videoObjectDefiningMetadata = new Video();
		
		//���J����Ȃ�"public"�A�����"unlisted"���g�p(�����N��m���Ă���l��������Ȃ�)
		VideoStatus status = new VideoStatus();
		status.setPrivacyStatus("unlisted");
		videoObjectDefiningMetadata.setStatus(status);
		
		// ���^�f�[�^(����Ɋ֌W����f�[�^)��ݒ肷��I�u�W�F�N�g
    	VideoSnippet snippet = new VideoSnippet();
    	
    	//�^�C�g����ݒ�
    	snippet.setTitle(title);
    	//����Ɋւ��������ݒ�
    	snippet.setDescription(description);
    	
    	// ���^�f�[�^����
    	videoObjectDefiningMetadata.setSnippet(snippet);
    	
    	run();
	}
	//�A�b�v���[�h�p�X���b�h
	@Override
	public void run(){
		try{
			InputStreamContent mediaContent = new InputStreamContent(
					VIDEO_FILE_FORMAT, new BufferedInputStream(new FileInputStream(this.uploadedFile)));
			mediaContent.setLength(this.uploadedFile.length());
        	
			/*
			 * ������youtube�ɓ�����A�b�v���[�h
			 * The upload command includes: 1. Information we want returned after file is successfully
			 * uploaded. 2. Metadata we want associated with the uploaded video. 3. Video file itself.				 
			 */
			
			YouTube.Videos.Insert videoInsert = youtube.videos()
					.insert("snippet,statistics,status", videoObjectDefiningMetadata, mediaContent);
			// Set the upload type and add event listener.
	    	MediaHttpUploader uploader = videoInsert.getMediaHttpUploader();
	    	/*
	    	 * Sets whether direct media upload is enabled or disabled. True = whole media content is
	    	 * uploaded in a single request. False (default) = resumable media upload protocol to upload
	    	 * in data chunks.
	    	 */
	    	uploader.setDirectUploadEnabled(false);
	    	// Execute upload.
	    	Video returnedVideo = videoInsert.execute();
	    	// Print out returned results.
	    	System.out.println("\n================== Returned Video ==================\n");
	    	System.out.println("  - Id: " + returnedVideo.getId());
	    	System.out.println("  - Title: " + returnedVideo.getSnippet().getTitle());
	    	System.out.println("  - Tags: " + returnedVideo.getSnippet().getTags());
	    	System.out.println("  - Privacy Status: " + returnedVideo.getStatus().getPrivacyStatus());
	    	System.out.println("  - Video Count: " + returnedVideo.getStatistics().getViewCount());
		}catch(FileNotFoundException e){
			System.out.println(e);
		}catch(IOException e){
			System.out.println(e);
		} catch (Throwable t) {
    		System.err.println("Throwable: " + t.getMessage());
    		t.printStackTrace();
    	}
	}
}
