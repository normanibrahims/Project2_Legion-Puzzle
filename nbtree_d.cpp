#include <limits.h>
#include <malloc.h>
#include "nbtree_d.h"

void nbCreate(nbAddr *x){
	(*x)=NULL;
}

nbAddr nbCNode(nbType X){
	nbAddr newNode;
	newNode=(nbAddr) malloc(sizeof(ElmtTree));
	if (newNode != NULL){
		newNode->fs=NULL;
		newNode->data=X;
		newNode->nb=NULL;
		newNode->parent=NULL;
	}
	return newNode;
}

nbAddr nbInsert(nbAddr *tRoot, nbAddr parent, nbType X){
	
	nbAddr newNode, temp;
	
	newNode=nbCNode(X);
	if (newNode !=NULL){ //Jika penciptaan node baru berhasil
		if (parent==NULL) //JIka belum terdapat root
			*tRoot=newNode;
		else{
			temp=parent;
			if (temp->fs != NULL){
				temp=temp->fs;
				while(temp->nb!=NULL)
					temp=temp->nb;
				temp->nb=newNode;
			}else
				temp->fs=newNode;
			newNode->parent=parent;
		}
	}
	return(newNode);
}

nbAddr nbSearch(nbAddr root, nbType src){
	nbAddr nSrc;
	if (root!=NULL){
		if (root->data.move==src.move && root->data.reverse==src.reverse && root->fs==NULL)
			return root;
		else{
			nSrc=nbSearch(root->fs,src);
			if (nSrc==NULL)
				return nbSearch(root->nb,src);
			else
				return nSrc;
		}
	}
	else{
		return NULL;
	}
}

void nbUpgrade(nbAddr *root){
	nbAddr temp;
	temp=(*root)->nb;
	if ((*root)->fs==NULL)
		(*root)->fs=temp;
	while(temp!=NULL){
		temp->parent=*root;
		temp=temp->nb;
	}
}

void nbDelete(nbAddr *pDel, nbAddr *pTree){
	nbAddr pCur;
	pCur=*pDel;

	if (pCur==*pTree && pCur->fs==NULL){
		pTree=NULL;
		return;
	}

	while(pCur->fs!=NULL){
		pCur=pCur->fs;
	}

//	while (pCur!=*pDel){
//		nbUpgrade(&pCur);
//		if (pCur->parent!=NULL){
//			pCur->nb=pCur->parent->nb;
//		}
//		else{
//			pCur->nb=NULL;
//			pCur=pCur->parent;
//		}
//	}

	if (pCur->parent!=NULL){
		pCur->parent->fs=pCur->fs;
	}
	if (pCur->fs!=NULL){
		pCur->fs->parent=pCur->parent;
	}
	if (pCur->parent==NULL){
		*pTree=pCur;
	}
}

//void delete_node(nbTree *pTree){
//	
//	nbAddr pdel, temp, tempNb;
//	pdel=pTree->root;
//	nbType value;
//	int i=0;
//	printf("\n\nNode yg di delete : ");
//	scanf("%d", &value);
//	
//	if(pTree->root != NULL){
//		pdel=nbSearch(pTree->root,value);
//		if(pdel->fs != NULL){
//			temp = pdel;
//			while(temp->fs != NULL){
//				temp->info = temp->fs->info;
//				if(temp->fs->nb != NULL){
//					tempNb=temp->fs->nb;
//					//temp=temp->fs;
//					
//				}
//				temp=temp->fs;
//				temp->nb=tempNb;
//			}
//			
//		}
//		else if(pdel->fs==NULL){
//			temp=pdel->parent;
//			
//			if(temp->fs==pdel){
//				temp->fs=pdel->nb;
//			}
//			else{
//				temp=temp->fs;
//				while(temp->nb != NULL ){
//					if(temp->nb==pdel){
//						temp->nb = temp->nb->nb;
//						
//					}
//					else{
//						temp=temp->nb;
//					}
//				}
//			}
//		}
//		//null_node(&pdel);
//		free(pdel);
//	}
//	else{
//		printf("Tree Kosong!!!");
//	}
//}

int nbDepth(nbAddr root)
{
	int y=0,z=0;

	if(root==NULL)
		return -1;
	y=nbDepth(root->fs);
	z=nbDepth(root->nb);
	if (y > z)
		return (y);
	else
		return (z+1);
}

/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root){
	if (root!=NULL){
		nbPost(root->fs);
		printf("%d ", root->data);
		nbPost(root->nb);
	}
/*
// Post Order Non Rekursif -> selesai
nbAddr pCur;
	boolean arah;
	arah=0;

	pCur=pTree.root;
	do{
		if(pCur->fs!=NULL && arah==0)
			pCur=pCur->fs;
		else{
			printf("%d ", pCur->info);
			arah=0;
			if (pCur->nb!= NULL)
				pCur=pCur->nb;
			else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);
*/
}

void nbPre(nbAddr root){
	if (root!=NULL){
		printf("%d %d %d %d", root->data.atas,root->data.bawah,root->data.kanan,root->data.kiri);
		printf("\t\tmove %d reverse %d\n",root->data.move,root->data.reverse);
		nbPre(root->fs);
		nbPre(root->nb);
	}
/*
// Pre order Non Rekursif -> Selesai
nbAddr pCur;
	boolean arah;
	arah=0;

	pCur=pTree.root;
	printf("%d ", pCur->info);
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
			printf("%d ", pCur->info);
		}else{
			arah=0;
			if (pCur->nb!= NULL){
				pCur=pCur->nb;
				printf("%d ", pCur->info);
			}else{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);*/

}

//void nbIn(nbAddr root){
//	if (root!=NULL){
//		nbIn(root->fs);
//		if (root->fs==NULL) printf("%d ", root->info);
//		if (root->parent !=NULL)
//			if (root->parent->fs==root)
//				printf("%d ", root->parent->info);
//		nbIn(root->nb);
//	}

/*
// Inorder non rekursif -> belum selesai
	nbAddr pCur;
	int arah;
	arah=0;

	pCur=pTree.root;
	do{
		if(pCur->fs!=NULL && arah==0){
			pCur=pCur->fs;
		}else{
			if (pCur->nb!= NULL){
				printf("%d ", pCur->info);
				pCur=pCur->nb;
			}else{
					printf("%d ", pCur->info);
					arah=1;
				pCur=pCur->parent;
			}
			if (arah==0 && pCur->parent!=NULL)
				printf("%d ", pCur->parent->info);
			if (arah==0) arah=1;
		}
	}while(pCur!=NULL);
*/
//}



void nbLevelOrder(nbAddr root,int curLevel, int desLevel)
{
	if(root!=NULL)
	{
		if(curLevel==desLevel)
			printf("%d  ",root->data);
		nbLevelOrder(root->fs,curLevel+1,desLevel);
		nbLevelOrder(root->nb,curLevel,desLevel);
	}
}

void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (node!=NULL){
		printf("%s%d\n",tab,node->data);
		nbPrint(node->fs,tempTab);
		nbPrint(node->nb,tab);
	}
}
