//=============================================================================
//  RogueList.h
//
//  2015.09.02 by Abe Pralle
//=============================================================================
#pragma once
#ifndef ROGUE_LIST_H
#define ROGUE_LIST_H

//-----------------------------------------------------------------------------
//  List Types
//-----------------------------------------------------------------------------
RogueType* RogueTypeByteList_create( RogueVM* vm );
RogueType* RogueTypeObjectList_create( RogueVM* vm );
void       RoguePrintFn_object_list( void* list_ptr, RogueStringBuilder* builder );

//-----------------------------------------------------------------------------
//  List Objects
//-----------------------------------------------------------------------------
struct RogueList
{
  RogueObject  object;
  RogueArray*  array;
  RogueInteger count;
};

RogueList* RogueList_create( RogueType* list_type, RogueType* array_type, RogueInteger initial_capacity );
RogueList* RogueByteList_create( RogueVM* vm, RogueInteger initial_capacity );
RogueList* RogueObjectList_create( RogueVM* vm, RogueInteger initial_capacity );

RogueList* RogueList_add_object( RogueList* THIS, void* object );
RogueList* RogueList_reserve( RogueList* THIS, RogueInteger additional_capacity );
RogueList* RogueList_resize( RogueList* THIS, RogueInteger new_count );

#endif // ROGUE_LIST_H
