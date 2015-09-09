//=============================================================================
//  RogueCmd.h
//
//  2015.08.29 by Abe Pralle
//=============================================================================
#pragma once
#ifndef ROGUE_CMD_H
#define ROGUE_CMD_H

#include "Rogue.h"

typedef void       (*RogueCmdInitFn)( void* cmd );
typedef void       (*RogueCmdPrintFn)( void* cmd, RogueStringBuilder* builder );
typedef RogueType* (*RogueCmdTypeFn)( void* cmd );

RogueType* RogueCmdTypeFn_same_as_operand( void* cmd );

//-----------------------------------------------------------------------------
//  RogueCmdType
//-----------------------------------------------------------------------------
struct RogueCmdType
{
  RogueAllocation allocation;
  RogueVM*        vm;
  RogueTokenType  token_type;
  RogueInteger    object_size;
  const char*     name;

  RogueCmdInitFn  init_fn;
  RogueCmdPrintFn print_fn;
  RogueCmdTypeFn  type_fn;
};

RogueCmdType* RogueCmdType_create( RogueVM* vm, RogueTokenType token_type,
    const char* name, RogueInteger object_size );

void RogueCmdLiteralInteger_print( void* cmd, RogueStringBuilder* builder );

//-----------------------------------------------------------------------------
//  RogueCmd
//-----------------------------------------------------------------------------
struct RogueCmd
{
  RogueAllocation allocation;
  RogueCmdType*   type;
  RogueString*    filepath;
  RogueInteger    line;
  RogueInteger    column;
};

struct RogueCmdStatementList
{
  RogueCmd     cmd;
  RogueVMList* statements;
};

void RogueCmdStatementList_init( void* cmd );

struct RogueCmdLiteralInteger
{
  RogueCmd     cmd;
  RogueInteger value;
};

struct RogueCmdUnaryOp
{
  RogueCmd  cmd;
  RogueCmd* operand;
};

struct RogueCmdBinaryOp
{
  RogueCmd  cmd;
  RogueCmd* left;
  RogueCmd* right;
};

void* RogueCmd_create( RogueCmdType* of_type );
void  RogueCmd_throw_error( RogueCmd* THIS, const char* message );

#endif // ROGUE_CMD_H
