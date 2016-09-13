import java.io.File;
import java.io.IOException;
import java.nio.file.*;
import java.nio.file.WatchEvent.Kind;
import java.util.concurrent.TimeUnit;

public class DirMonitor extends Thread{
	//�Ď���̃p�X
	private String dirName;
	//�ҋ@����(s)
	private int waitCnt = 10;
	private MyVideo myVideo;
	/*
	 * �R���X�g���N�^
	 * path:�Ď���̃p�X
	 */
	DirMonitor(String path){
		this.dirName = path;
		myVideo = new MyVideo();
	}
	
	@Override
	public void run(){
		Path dirPath = new File(dirName).toPath();
		FileSystem fs = dirPath.getFileSystem();
		try(WatchService watcher = fs.newWatchService()){
			
			//�f�B���N�g���ɑ΂��ĊĎ��T�[�r�X��o�^����
			 WatchKey watchKey = dirPath.register(watcher, new Kind[]{
					 StandardWatchEventKinds.ENTRY_CREATE, // �쐬
			 } ); // �I�v�V�����̏C���q�A�s�v�Ȃ�΋�z��
			 
			 // �Ď����L���ł��邩����A���[�v����.
			 // (�Ď���cancel����邩�A�Ď��T�[�r�X����~�����ꍇ��false�ƂȂ�)
			 while(watchKey.isValid()){
				 try{
                     // �X���b�h�̊��荞�� = �I���v���𔻒肷��.
                     if (Thread.currentThread().isInterrupted()) {
                         throw new InterruptedException();
                     }
                     
                     // �t�@�C���ύX�C�x���g����������܂őҋ@����.
                     WatchKey detecedtWatchKey = watcher.poll(500, TimeUnit.MILLISECONDS);
                     if (detecedtWatchKey == null) {
                         // �^�C���A�E�g
                         continue;
                     }
                     
                     if(detecedtWatchKey.equals(watchKey)){
                    	 //�ǉ����ꂽ�t�@�C�����擾��.remove()�����s����
                    	 for(@SuppressWarnings("rawtypes") WatchEvent event : detecedtWatchKey.pollEvents()){
                    		 Path file = (Path)event.context();
                    		 myVideo.remove(file.toString());
                    	 }
                     }
                     
                     // �C�x���g�̃n���h�����O�Ɏ��Ԃ�������P�[�X��
                     // Sleep�ŃG�~�����[�g����.
                     // (���̊Ԃ̃t�@�C���ύX�C�x���g����肱�ڂ����ۂ����m���߂���)
                     for (int cnt = 0; cnt < waitCnt; cnt++) {
                         Thread.sleep(1000);
                     }
                     
                     //�C�x���g�̎�t���ĊJ����
                     detecedtWatchKey.reset();
				 }catch(InterruptedException e){
					 watchKey.cancel();
				 }
			 }
		} catch (RuntimeException | IOException e) {
			e.printStackTrace();
		}
	}
}
