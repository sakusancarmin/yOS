/* �v���g�^�C�v�錾 */
void io_hlt(void);
void write_mem8(int addr, int data);

void HariMain(void){
	/* i ��32�r�b�g�̐����^ */
	int i;

	for(i = 0xa0000; i <= 0xaffff; i++){
		/* MOV BYTE [i], 15 */
		/* ���̉�ʃ��[�h�Ŏg�p����VRAM���ׂĂ�15�Ԗڂ̐F������B
		   15�Ԗڂ̐F�͂��܂��ܔ��������̂ŁA��ʑS�̂����ɂȂ�B */
		write_mem8(i, 15);
	}
	/* ��L��for���́A�ȉ��̃v���O�����ɓ�����

		MOV i,0xa0000;
	label:
		if(i <= 0xaffff){
			MOV BYTE[i], 15;
			ADD i, 1;
			goto label;
		}
	*/

	for(;;){
		io_hlt();
	}
}


	