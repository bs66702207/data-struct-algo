ADT List
	Data
		{a1,a2...an}
	Operation
		InitList(*L);
		ListEmpty(L);
		ClearList(*L);
		GetElem(L, i, *e);//i=index, e为输出的List的元素
		LocateElem(L, e);//查找e是否存在于List中，如果存在则返回index，否则返回0
		ListInsert(*L, i, e);
		ListDelete(*L, i, *e);//删除后，用e返回其元素
		ListLength(L);
endADT
