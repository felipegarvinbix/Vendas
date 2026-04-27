/****************************************************************************************************************************************
	File:		E_CATEGORIAS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Leitura da tabela de categorias onde contém a descrição das categorias dos produtos.
	
****************************************************************************************************************************************/

Categorias:
LOAD
    category_id,
    category_name,
    description
FROM $(vDadosBase)northwind_xls.xlsx 
(ooxml, embedded labels, table is categories);

STORE Categorias INTO $(vDadosQVD)E_CATEGORIAS.qvd (qvd);
DROP TABLE Categorias;


