; hello-os
; TAB=4

	ORG	0x7c00	;���̃v���O�������ǂ��ɓǂݍ��܂��̂�
; �ȉ��͕W���I��FAT12�t�H�[�}�b�g�t���b�s�[�f�B�X�N�̂��߂̋L�q

	JMP	entry
	DB	0x90

; �v���O�����{��

entry:
	MOV	AX, 0	; ���W�X�^������
	MOV	SS, AX
	MOV	SP, 0x7c00
	MOV	DS, AX
	MOV	ES, AX

	MOV	SI, msg
putloop:
	MOV	AL, [SI]
	ADD	SI, 1	; SI��1�𑫂�
	CMP	AL, 0
	JE	fin
	MOV	AH, 0x0e	; �ꕶ���\���t�@���N�V����
	MOV	BX, 15		; �J���[�R�[�h
	INT	0x10		; �r�f�IBIOS���o��
	JMP	putloop
	
fin:
	HLT			; ��������܂�CPU���~������
	JMP	fin
	
msg;
DB	0x0a, 0x0a	; ���s���ӂ���
	DB	"Good evening"
	DB	0x0a
	DB	0
