void io_hlt(void);	/* �v���g�^�C�v�錾 */

void HariMain(void){
	int i;
	char *p;	/* p�Ƃ����ϐ��́ABYTE[...]�p�̔Ԓn */

	for(i = 0xa0000; i <= 0xaffff; i++){

		p = (char*)i;	/* �Ԓn���� */
		*p = i & 0x0f;	
		/* p�ɂ͔Ԓn�������Ă��āA*������Ɓu���̔Ԓn���w���������i�̒��g�j�v
		   �Ƃ����Ӗ��ɂȂ�B */

		/* ����� write_mem8(i, i & 0x0f); �̑���ɂȂ� */

	}

	for(;;){
		io_hlt();
	}
}