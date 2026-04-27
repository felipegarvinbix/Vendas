/****************************************************************************************************************************************
	File:		T_DIM_CALENDARIO.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Gerar o calendário canonico.
	
****************************************************************************************************************************************/

Calendario_tmp:
LOAD
	KEY_CALENDARIO						AS KEY_CALENDARIO,
	DAT_DATA_PEDIDO						AS DAT_DATA,
	'Data Pedido' 						AS DES_TIPO_DATA
RESIDENT Pedidos;

CONCATENATE(Calendario_tmp)

LOAD
	KEY_CALENDARIO						AS KEY_CALENDARIO,
	DAT_DATA_ENVIO						AS DAT_DATA,
	'Data Envio' 						AS DES_TIPO_DATA
RESIDENT Pedidos;

Calendario:
LOAD
	KEY_CALENDARIO						AS KEY_CALENDARIO,
	DAT_DATA							AS DAT_DATA,
	DES_TIPO_DATA						AS DES_TIPO_DATA,
	YEAR(DAT_DATA) 						AS NUM_ANO,
	MONTH(DAT_DATA)						AS DES_MÊS,
	DAY(DAT_DATA)						AS NUM_DIA,
	NUM#(DATE(DAT_DATA, 'yyyyMM'))  	AS NUM_ANOMÊS,
	TEXT(DATE(DAT_DATA, 'MMM-yyyy'))	AS DES_ANOMÊS
RESIDENT Calendario_tmp;

DROP TABLE Calendario_tmp;