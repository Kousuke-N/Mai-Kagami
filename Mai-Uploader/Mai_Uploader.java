
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
	public static void main(String[] args) {
		
		//�t�H���_�Ď��p�C���X�^���X�쐬(video�t�H���_���Ď�)
		DirMonitor dirMonitor = new DirMonitor("./video");
		//�Ď��J�n
		dirMonitor.start();
		//temp�t�H���_����t�H���_����Ȃ��Ȃ�܂Ń��[�v
		File checkedFile = new File("\temp");
		while(!checkedFile.exists()){	}
		
		//temp�ɒǉ����ꂽ�t�@�C���̎擾
		String[] fileList = checkedFile.list();
		
		MyYouTube myYoutube;
		try {
			myYoutube = new MyYouTube();
			//�A�b�v���[�h����t�@�C����ǉ�				
			myYoutube.setVideo(new File(fileList[0]));
				
			//�t�@�C���ɏ���ǉ�����
			myYoutube.setMetadata(
					"Mai_Uploader test upload on "  + Calendar.getInstance().getTime(),
					"�����̓���̃e�X�g�A�b�v���[�h " + "on " + Calendar.getInstance().getTime()
					);
		} catch (Exception e) {
			e.printStackTrace();
		}
 	}
}