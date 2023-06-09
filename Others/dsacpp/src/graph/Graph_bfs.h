/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename Tv, typename Te> //广度优先搜索BFS算法（全图）
void Graph<Tv, Te>::bfs ( Rank s ) { //s < n
   reset(); int clock = 0; Rank v = s; //初始化
   do //逐一检查所有顶点
      if ( UNDISCOVERED == status ( v ) ) //一旦遇到尚未发现的顶点
         BFS ( v, clock ); //即从该顶点出发启动一次BFS
   while ( s != ( v = ( ( v+1 ) % n ) ) ); //按序号检查，故不漏不重
}

template <typename Tv, typename Te> //广度优先搜索BFS算法（单个连通域）
void Graph<Tv, Te>::BFS ( Rank v, int& clock ) { //v < n
   Queue<Rank> Q; //引入辅助队列
   status( v ) = DISCOVERED; Q.enqueue ( v ); //初始化起点
   dTime( v ) = clock; clock = 0; //dTime继承自前一联通/可达分量
   while ( !Q.empty() ) { //在Q变空之前，不断
      Rank v = Q.dequeue(); //轮到队首顶点v接受访问
      for ( Rank u = firstNbr( v ); -1 < u; u = nextNbr( v, u ) ) //枚举v的所有邻居u
         if ( UNDISCOVERED == status ( u ) ) { //若u尚未被发现，则
            status( u ) = DISCOVERED; Q.enqueue ( u ); dTime( u ) = dTime( v ) + 1; //发现该顶点
            type( v, u ) = TREE; parent( u ) = v; //引入树边拓展支撑树
         } else { //若u已被发现，或者甚至已访问完毕，则
            type( v, u ) = CROSS; //将(v, u)归类于跨边
         }
      status( v ) = VISITED; fTime( v ) = clock++; //v访问完毕
      if ( Q.empty() )
         clock = dTime(v) + 1; //为可能的下一连通/可达分量，预备好起始顶点的dTime
      else if ( dTime( v ) < dTime( Q.front() ) )
         clock = 0; //dTime的增加，意味着开启新的一代
   }
}