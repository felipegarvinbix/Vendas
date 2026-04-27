/****************************************************************************************************************************************
	File:		STORES.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Dar STORE nas tabelas carregadas anteriormente no script.
	
****************************************************************************************************************************************/

STORE Funcionario INTO $(vDadosQVD)T_DIM_FUNCIONARIOS.qvd (qvd);
DROP TABLE Funcionario;

STORE Pedidos INTO $(vDadosQVD)T_FATO_PEDIDOS.qvd (qvd);
DROP TABLE Pedidos;

STORE Produtos INTO $(vDadosQVD)T_DIM_PRODUTOS.qvd (qvd);
DROP TABLE Produtos;

STORE Clientes INTO $(vDadosQVD)T_DIM_CLIENTES.qvd (qvd);
DROP TABLE Clientes;

STORE Expedidores INTO $(vDadosQVD)T_DIM_EXPEDIDORES.qvd (qvd);
DROP TABLE Expedidores;

STORE Calendario INTO $(vDadosQVD)T_DIM_CALENDARIO.qvd (qvd);
DROP TABLE Calendario;
