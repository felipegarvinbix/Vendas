/****************************************************************************************************************************************
	File:		T_DIM_PRODUTOS.INC 
		
	Author:		Felipe Garvin
	Email:		felipe.garvin@bix-tech.com
	
	Version:	1.0
	Date:		19/07/2024
	
	Objetivo: Transformar a tabela E_PRODUTOS em uma tabela DIMENSÃO.
	
****************************************************************************************************************************************/

// Mapeamento para descobrir qual o fornecedor do produto
Mapa_Fornecedor:
MAPPING LOAD
    supplier_id,
    company_name
FROM $(vDadosQVD)E_FORNECEDORES.qvd (qvd);

// Mapeamento para descobrir qual a categoria do produto
Mapa_Categoria:
MAPPING LOAD
    category_id,
    category_name
FROM $(vDadosQVD)E_CATEGORIAS.qvd (qvd);

Produtos:
LOAD
    product_id										    AS KEY_PRODUTO,
    product_name									    AS DES_PRODUTO_NOME,
    APPLYMAP('Mapa_Fornecedor', supplier_id, NULL())    AS DES_FORNECEDOR,
    APPLYMAP('Mapa_Categoria', category_id, NULL())     AS DES_CATEGORIA,
    NUM(unit_price,'#.##0,00') * units_in_stock         AS VLR_TOTAL_ESTOQUE, // cálculo para definir o valor total do estoque, multiplicando unidades do estoque pelo preço unitário                    
    units_in_stock									    AS QTD_UNIDADES_NO_ESTOQUE,
    units_on_order									    AS QTD_UNIDADES_EM_PROCESSAMENTO,
    IF(units_in_stock > reorder_level,
        IF(
            (units_in_stock - reorder_level)
            < 11
            , 2, 1
        ), 
    0)                                                  AS FLG_ESTOQUE_MINIMO, // cálculo para definir os produtos que estão com menos unidades no estoque do que é necessário
    reorder_level                                       AS QTD_ESTOQUE_MINIMO,
    IF(discontinued = '1', 'Sim', 'Não')                AS FLG_PRODUTO_DESCONTINUADO // verifica se o produto foi descontinuado ou está ativo
FROM $(vDadosQVD)E_PRODUTOS.qvd (qvd);

