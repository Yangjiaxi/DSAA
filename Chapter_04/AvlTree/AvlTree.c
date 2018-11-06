#include "AvlTree.h"

typedef struct AvlNode
{
  int Element;
  AvlTree Left;
  AvlTree Right;
  int Height;
} AvlNode;

static int Max(int a, int b)
{
  return a > b ? a : b;
}

static int Height(Position P)
{
  if (P == NULL)
  {
    return -1;
  }
  else
  {
    return P->Height;
  }
}

AvlTree MakeEmpty(AvlTree T) //递归释放所有节点，相当于构造一个空树
{
  if (T != NULL)
  {
    MakeEmpty(T->Left);
    MakeEmpty(T->Right);
    free(T);
  }
  return T;
}

Position Find(int X, AvlTree T) //在树T中寻找元素X的位置，并返回指向节点的指针，未找到返回NULL
{
  if (T == NULL) //树T为空，代表寻找到叶子仍未找到目标元素；或树T本来就为空
  {
    return NULL;
  }
  else
  {
    if (X < T->Element) //比根节点大，进入左子树搜索
    {
      return Find(X, T->Left);
    }
    else //比根节点小，进入右字数搜索
    {
      return Find(X, T->Right);
    }
  }
}

Position FindMin(AvlTree T) //寻找树中最小元素
{
  if (T == NULL)
  {
    return NULL;
  }
  else
  {
    if (T->Left == NULL) //当前节点的左子树为空，说明该节点保存着最小值
    {
      return T;
    }
    else //左子树存在，必然保存着比当前节点小的值，进入左子树搜索
    {
      return FindMin(T->Left);
    }
  }
}

Position FindMax(AvlTree T) //寻找树中最大元素（不使用递归）
{
  if (T != NULL)
  {
    while (T->Right != NULL)
    {
      T = T->Right;
    }
  }
  return T;
}

static Position SingleRotateWithLeft(Position K2) //处理向左儿子的左子树插入元素
{
  Position K1;
  K1 = K2->Left;
  K2->Left = K1->Right;
  K1->Right = K2;
  K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
  K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
  return K1;
}

static Position SingleRotateWithRight(Position K2) //处理向右儿子的右子树插入元素
{
  Position K1;
  K1 = K2->Right;
  K2->Right = K1->Left;
  K1->Left = K2;
  K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
  K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
  return K1;
}

static Position DoubleRotateWithLeft(Position K3) //处理向左儿子的右子树插入节点
{
  K3->Left = SingleRotateWithRight(K3->Left);
  return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3) //处理向右儿子的左子树插入节点
{
  K3->Right = SingleRotateWithLeft(K3->Right);
  return SingleRotateWithRight(K3);
}

static Position Fix(Position K2) //修复不平衡的节点：不平衡的意思是他的左子树和右子树高度差达到2
{
  if (Height(K2->Left) > Height(K2->Right))
  {
    //K2左儿子的左儿子的高度大于K2的左儿子的右儿子的高度, 执行左单旋转, 否则执行左-右双旋转
    if (Height(K2->Left->Left) >= Height(K2->Left->Right))
      K2 = SingleRotateWithLeft(K2);
    else if (Height(K2->Left->Left) < Height(K2->Left->Right))
      K2 = DoubleRotateWithLeft(K2);
  }
  else if (Height(K2->Left) < Height(K2->Right))
  {
    //K2右儿子的右儿子的高度大于K2的右儿子的左儿子的高度, 执行右单旋转, 否则执行右-左双旋转
    if (Height(K2->Right->Right) >= Height(K2->Right->Left))
      K2 = SingleRotateWithRight(K2);
    else if (Height(K2->Right->Right) < Height(K2->Right->Left))
      K2 = DoubleRotateWithRight(K2);
  }
  return K2;
}

AvlTree Insert(int X, AvlTree T)
{
  if (T == NULL)
  {
    T = (AvlNode *) malloc(sizeof(AvlNode));
    if (T == NULL)
    {
      printf("ERROR:Out of space!\n");
      exit(-1);
    }
    else
    {
      T->Element = X;
      T->Height = 0;
      T->Left = T->Right = NULL;
    }
  }
  else
  {
    if (X < T->Element) //进入左子树插入
    {
      T->Left = Insert(X, T->Left);
      if (Height(T->Left) - Height(T->Right) == 2) //该节点破坏了AVL平衡条件
      {
        T = Fix(T);
      }
    }
    else if (X > T->Element) //进入右子树插入
    {
      T->Right = Insert(X, T->Right);
      if (Height(T->Right) - Height(T->Left) == 2) //该节点破坏了AVL平衡条件
      {
        T = Fix(T);
      }
    }
    //Else : X is already EXISTED, do nothing instead
  }
  T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
  return T;
}

AvlTree Delete(int X, AvlTree T) //删除树中值为X的节点
{
  Position TmpCell; //相当于中间变量
  if (T == NULL)    //始终未找到
  {
    printf("Element [%d] Not Found", X);
  }
  else if (X < T->Element) //值比节点元素小，去左子树
  {
    T->Left = Delete(X, T->Left); //进入左子树删除元素X，并将左子树替换为删除后的树
  }
  else if (X > T->Element) //大，去右子树
  {
    T->Right = Delete(X, T->Right);
  }
  else if (T->Left && T->Right) //此时X == Element开始删除
  {
    //这里左右子树均存在，删除一个有两个儿子的节点比较复杂，故进行转换：
    TmpCell = FindMin(T->Right); //将节点的值替换为右子树中最小的值，然后删除右子树中该最小的值
    T->Element = TmpCell->Element;
    T->Right = Delete(T->Element, T->Right);
  }
  else
  {
    //这里左右子树不全存在或全不存在，用存在的子树或NULL替换当前节点，然后释放当前节点（中间变量）
    TmpCell = T;
    if (T->Left == NULL) //左子树为空
    {
      T = T->Right;
    }
    else if (T->Right == NULL) //右子树为空
    {
      T = T->Left;
    }
    free(TmpCell);
  }
  //开始修复(如果有)
  if (T != NULL)
  {
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    if ((Height(T->Left) - Height(T->Right) >= 2) || (Height(T->Right) - Height(T->Left) >= 2))
    {
      //由于是递归删除，不用保存被删除元素的父节点，每层递归都会执行平衡检查，相当于从被删除节点一路向上检查
      T = Fix(T);
      T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    }
  }
  return T;
}

void InorderTreeWalk(AvlTree T)
{
  if (T == NULL)
  {
    return;
  }
  else
  {
    if (T->Left)
    {
      InorderTreeWalk(T->Left);
    }
    printf("%d ", T->Element);
    if (T->Right)
    {
      InorderTreeWalk(T->Right);
    }
  }
}

void PreTreeWalk(AvlTree T)
{
  if (T == NULL)
  {
    return;
  }
  else
  {
    printf("%d ", T->Element);
    if (T->Left)
    {
      PreTreeWalk(T->Left);
    }
    if (T->Right)
    {
      PreTreeWalk(T->Right);
    }
  }
}

void PostTreeWalk(AvlTree T)
{
  if (T == NULL)
  {
    return;
  }
  else
  {
    if (T->Left)
    {
      PostTreeWalk(T->Left);
    }
    if (T->Right)
    {
      PostTreeWalk(T->Right);
    }
    printf("%d ", T->Element);
  }
}