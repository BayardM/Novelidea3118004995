#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;
typedef char **HuffmanCode;
typedef struct{
    int weight;
    int parent,lch,rch;
}HTNode,*HuffmanTree;
int minHT(HuffmanTree HT,int n)//找最小和次小
{
    int i=0;
    int min1;
    int minWeight;
    while(HT[i].parent != 0)
    i++;
    minWeight = HT[i].weight;
    min1= i;
    for(;i<=n;i++)
    {
     if(HT[i].weight<minWeight&&HT[i].parent==0)
      {
        minWeight = HT[i].weight;
        min1= i;
      }
    }
    HT[min1].parent=1;
    return min1;
}
void Select(HuffmanTree HT,int n,int *s1,int *s2)  //选择权重最小的两个,返回他们的下标
{
    *s1=minHT(HT,n);
    *s2=minHT(HT,n);
}
void CreateHuffmanTree(HuffmanTree HT,int n)   //创建哈夫曼树
{
    int s1,s2,m,i;
    if(n<=1) return;
    m=2*n-1;  //数组共有2n-1个元素
    HT=new HTNode[m+1];
    for(i=1;i<=m;i++)
    {
        HT[i].lch=0;HT[i].rch=0;HT[i].parent=0;  //全部置0
    }
    for(i=1;i<=n;i++)
    {
        cin>>HT[i].weight;
    }
    //产生n-1个结点
    for(i=n+1;i<=m;i++)
    {
        Select(HT,n,&s1,&s2);//选择权重最小的两个,返回他们的下标
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lch=s1;HT[i].rch=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
       for(i=1;i<=m;i++)
    cout<<HT[i].weight<<endl;
}
//哈夫曼编码
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n)  //叶子到根逆向求编码
{

   HC=new char *[n+1];  //分配n个字符串数组放编码
    if(!HC)
    {
        printf("HuffmanCode new faild!");
        return;
    }
     char *code = new char[n];//临时保存每次求得的赫夫曼编码串,因有n个叶子节点--->编码长度<=n-1
        if(!code)
            {
                printf("code malloc faild!");
                return;
            }

        code[n-1] = '\0';  //编码结束的标志
        //求每个字符的编码
        int i;
        for(i=1;i<=n;i++)
    {
            int current = i;           //定义当前访问的节点
            int father= HT[i].parent; //当前节点的父节点
            int start = n-1;           //每次编码的位置
        while(father != 0)     //从叶子开始直到根
        {
            if(HT[father].lch== current)   //如果是左孩子，则编码为0
            code[--start] = '0';
            else                              //如果是右孩子，则编码为1
            code[--start] = '1';
            current = father;
            father = HT[father].parent; //继续往上找
        }
        HC[i] = new char[n-start];//为第i个字符的编码分配空间
        if(!HC[i])
        {
            printf("HC[i] malloc faild!");
            return;
        }
        strcpy(HC[i],&code[start]);//把字符串复制到这里
    }
    delete code; //释放之前的保存编码串的临时空间
}
//哈夫曼解码
  void HuffmanDecode(HuffmanCode &HC,HuffmanTree HT,int n)
  {
      char *s;
      int p=0;
      HT[p].parent=0;
        for(int i=1;i<=n;i++)
      {
           s=HC[i];
        }
     for(int i=1;i<=n-1;i++)
     {
         if(s[i]=='0')
         {
             if(HT[p].lch!=0)
            {
                 HT[p]=HT[HT[p].lch];
             }
        }
         else if(s[i]=='1')
          {
              if(HT[p].rch!=0)
             {
                  HT[p]=HT[HT[p].rch];
              }
          }
        if(HT[p].lch==0&&HT[p].rch==0)
          {
              cout<<HT[p].weight;
              HT[p].parent=0;
          }
      }
  }


#endif // HUFFMAN_H_INCLUDED
