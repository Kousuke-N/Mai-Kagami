
import java.io.File;
import java.util.Calendar;

/*
 * �Q�l�y�[�W
 *  https://developers.google.com/youtube/v3/code_samples/java?hl=ja#upload_a_video 
 */

/*
 * �t�@�C���Ď�~youtube�A�b�v���[�h�܂ł̃v���Z�X�̐��������܂�
 * 1.temp�t�H���_����t�H���_�ɂ���
 * 2.video�t�H���_���Ď�(dirMonitor.start())�B�t�@�C�����ǉ����ꂽ��temp�Ɉړ�
 * 3.main�N���X��temp�t�H���_���Ď��B
 * 4.temp����t�H���_����Ȃ��Ȃ����炻�̃t�@�C���̃A�b�v���[�h�ɂ���
 * 5�D�A�b�v���[�h���I������炻�̃t�@�C��������1�ɖ߂�(2�ɂ��Ă͏�ɓ����Ă���)
 */

public class Mai_Uploader {
	//���������[�v������Ƃ��̎���(�b)
	private static int waittime = 10;
	public static void main(String[] args) {
		MyYouTube myYoutube = new MyYouTube();
		
//		while(true){
//			MyVideo myVideo = new MyVideo();
//			
//			//video�t�H���_����t�H���_����Ȃ��Ȃ�܂Ń��[�v
//			File video = new File("./video");
//			while(video.length() == 0){	}
//			
//			//video�t�H���_�ɓ����Ă���t�@�C���̃��X�g
//			File[] fileList = video.listFiles();
//		
//			try {
//				
//				//�A�b�v���[�h����t�@�C����ǉ�				
//				if(!myYoutube.setVideo(new File(fileList[0]))) continue;
//				
//				//�t�@�C���ɏ���ǉ�����
//				myYoutube.setMetadata(
//						"Mai_Uploader test upload on "  + Calendar.getInstance().getTime(),
//						"�����̓���̃e�X�g�A�b�v���[�h " + "on " + Calendar.getInstance().getTime()
//						);
//			} catch (Exception e) {
//				e.printStackTrace();
//			}
//		}
 	}
}