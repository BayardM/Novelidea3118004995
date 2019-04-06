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
int minHT(HuffmanTree HT,int n)//����С�ʹ�С
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
void Select(HuffmanTree HT,int n,int *s1,int *s2)  //ѡ��Ȩ����С������,�������ǵ��±�
{
    *s1=minHT(HT,n);
    *s2=minHT(HT,n);
}
void CreateHuffmanTree(HuffmanTree HT,int n)   //������������
{
    int s1,s2,m,i;
    if(n<=1) return;
    m=2*n-1;  //���鹲��2n-1��Ԫ��
    HT=new HTNode[m+1];
    for(i=1;i<=m;i++)
    {
        HT[i].lch=0;HT[i].rch=0;HT[i].parent=0;  //ȫ����0
    }
    for(i=1;i<=n;i++)
    {
        cin>>HT[i].weight;
    }
    //����n-1�����
    for(i=n+1;i<=m;i++)
    {
        Select(HT,n,&s1,&s2);//ѡ��Ȩ����С������,�������ǵ��±�
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lch=s1;HT[i].rch=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
       for(i=1;i<=m;i++)
    cout<<HT[i].weight<<endl;
}
//����������
void HuffmanCoding(HuffmanTree HT,HuffmanCode &HC,int n)  //Ҷ�ӵ������������
{

   HC=new char *[n+1];  //����n���ַ�������ű���
    if(!HC)
    {
        printf("HuffmanCode new faild!");
        return;
    }
     char *code = new char[n];//��ʱ����ÿ����õĺշ������봮,����n��Ҷ�ӽڵ�--->���볤��<=n-1
        if(!code)
            {
                printf("code malloc faild!");
                return;
            }

        code[n-1] = '\0';  //��������ı�־
        //��ÿ���ַ��ı���
        int i;
        for(i=1;i<=n;i++)
    {
            int current = i;           //���嵱ǰ���ʵĽڵ�
            int father= HT[i].parent; //��ǰ�ڵ�ĸ��ڵ�
            int start = n-1;           //ÿ�α����λ��
        while(father != 0)     //��Ҷ�ӿ�ʼֱ����
        {
            if(HT[father].lch== current)   //��������ӣ������Ϊ0
            code[--start] = '0';
            else                              //������Һ��ӣ������Ϊ1
            code[--start] = '1';
            current = father;
            father = HT[father].parent; //����������
        }
        HC[i] = new char[n-start];//Ϊ��i���ַ��ı������ռ�
        if(!HC[i])
        {
            printf("HC[i] malloc faild!");
            return;
        }
        strcpy(HC[i],&code[start]);//���ַ������Ƶ�����
    }
    delete code; //�ͷ�֮ǰ�ı�����봮����ʱ�ռ�
}
//����������
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
