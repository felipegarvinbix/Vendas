/****************************************************************************************************************************************
	File:		E_PRODUTOS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Leitura da tabela de produtos onded contém as informações de produtos da empresa.
	
****************************************************************************************************************************************/

Produtos:
LOAD
    product_id,
    product_name,
    supplier_id,
    category_id,
    quantity_per_unit,
    unit_price,
    units_in_stock,
    units_on_order,
    reorder_level,
    discontinued
FROM $(vDadosBase)northwind_xls.xlsx 
(ooxml, embedded labels, table is products);

STORE Produtos INTO $(vDadosQVD)E_PRODUTOS.qvd (qvd);
DROP TABLE Produtos;


