/*
# PostgreSQL Database Modeler (pgModeler)
# Sub-project: Core library (libpgmodeler)
# Description:Definição da classe Coluna que é utilizada pela classe Tabela.
# Creation date: 12/09/2006
#
# Copyright 2006-2012 - Raphael Araújo e Silva <rkhaotix@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/
#ifndef COLUMN_H
#define COLUMN_H

#include "tableobject.h"

class Column: public TableObject{
 protected:
  /* Armazena o nome anterior da coluna antes da mudança de nome da mesma.
     Este atributo auxilia no processo de referência de colunas adicionadas
     por relacionamentos. */
  QString old_name;

  //Indica se a coluna será não nula (com obrigatoriedade de preenchimento)
  bool not_null;

  //Tipo da coluna da tabela
  TipoPgSQL type;

  /* Valor padrão da coluna.
     Obs: O usuário deve formatar o valor padrão de
          acordo com o exigido por cada tipo do banco de dados.
          Ex.: para um varchar(10) o valor padrão deve ser 'abcdef'(incluindo o ') ou
               para uma data '2006-09-12' e assim por diante. */
  QString default_value;

 public:
  Column(void);

  //Define que a coluna é de preenchimento obrigatório (NOT NULL)
  void setNotNull(bool value);

  //Define o tipo da coluna
  void setType(TipoPgSQL type);

  /* Define o valor padrão da coluna. Devem ser informados junto ao valor
     as particularidades de cada tipo, como aspas, hifens e etc. */
  void setDefaultValue(const QString &value);

    /* Define o nome da coluna. Este método mantém o último nome da coluna
     armazenado para auxiliar os métodos de relacionamento de colunas
     adicionadas por relacionamentos com restrições/indices e sequencias */
  void setName(const QString &name);

  //Retorna se o campo é de preenchimento obrigatório
  bool isNotNull(void);

  //Retorna o tipo da coluna
  TipoPgSQL getType(void);

  //Retorna o valor padrão da coluna
  QString getDefaultValue(void);

  //Retorna a definição SQL ou XML do objeto
  QString getCodeDefinition(unsigned def_type);

  //Retorna o nome anterior da coluna
  QString getOldName(bool format=false);

  //Obtém a referência ao tipo da coluna na forma [esquema].tabela.nome_coluna%TYPE
  QString getTypeReference(void);

  void operator = (Column &col);

  friend class Tabela;
};

#endif