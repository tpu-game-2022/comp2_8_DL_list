#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"


// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->pPrev = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
	l->footer = NULL;
}


// 先頭にデータを追加
void push_front(list* l, node* p)
{
	p->pNext = l->header;
	l->header = p;
	if (!l->footer)
		l->footer = p;
	else
		p->pNext->pPrev = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	p->pPrev = l->footer;
	l->footer = p;
	if (!l->header)
		l->header = p;
	else
		p->pPrev->pNext = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if ((!p->pNext) && (!p->pPrev))
		initialize_list(&*l);
	else if (!p->pNext)
	{
		p->pPrev->pNext = NULL;
		l->footer = p->pPrev;
	}
	else if (!p->pPrev)
	{
		p->pNext->pPrev = NULL;
		l->header = p->pNext;
	}
	else
	{
		p->pPrev->pNext = p->pNext;
		p->pNext->pPrev = p->pPrev;
	}
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (!p->pNext);
	else if (!p->pNext->pNext)
	{
		p->pNext = NULL;
		l->footer = p;
	}
	else
	{
		p->pNext = p->pNext->pNext;
		p->pNext->pPrev = p;
	}
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (!p->pPrev);
	else if (!p->pPrev->pPrev)
	{
		p->pPrev = NULL;
		l->header = p;
	}
	else
	{
		p->pPrev->pPrev->pNext = p;
		p->pPrev = p->pPrev->pPrev;
	}
}


// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;

	return NULL;
}

// pの前のノードを取得
node* get_prev(list* l, node* p)
{
	if (!p) return NULL;
	return p->pPrev;

	return NULL;
}
