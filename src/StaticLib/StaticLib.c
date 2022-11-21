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
	if (l -> header) 
	{
		l-> header -> pPrev = p;
		p -> pNext = l -> header;
	}
	else 
	{
		l -> footer = p;
	}
	l -> header = p;
}

// 末尾にデータを追加
void push_back(list* l, node* p)
{
	if (l -> footer) 
	{
		l -> footer -> pNext = p;
		p -> pPrev = l -> footer;
	}
	else 
	{
		l -> header = p;
	}
	l -> footer = p;
}

// pのノードを削除
void remove_node(list* l, node* p)
{
	if (!p -> pPrev && !p -> pNext) 
	{
		initialize_list(l);
	}
	else 
	{
		if (!p -> pPrev) {
			l -> header = p -> pNext;
			p -> pNext -> pPrev = NULL;
			l -> header -> pNext = p -> pNext -> pNext;
		}
		else if (!p -> pNext) 
		{
			l -> footer = p -> pPrev;
			p -> pPrev -> pNext = NULL;
			l -> footer -> pPrev = p -> pPrev -> pPrev;
		}
		else {
			p->pNext->pPrev = p->pPrev;
			p->pPrev->pNext = p->pNext;
		}
	}
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (p -> pNext) 
	{
		if (!p -> pNext -> pNext) 
		{
			p -> pNext = NULL;
			l -> footer = p;
		}
		else 
		{
			remove_node(l, p -> pNext);
		}
	}
}

// pの前のノードを削除
void remove_prev(list* l, node* p)
{
	if (p -> pPrev) 
	{
		if (!p -> pPrev -> pPrev) 
		{
			p -> pPrev = NULL;
			l -> header = p;
		}
		else 
		{
			remove_node(l, p -> pPrev);
		}
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
