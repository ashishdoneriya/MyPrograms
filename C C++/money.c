#include<stdio.h>
int main() {
	int loop, notes, need, arr[100], collected, flag, i;
	scanf( "%d", &loop );
	while(loop--){
		collected=0;flag=0;
		scanf("%d %d",&notes,&need);
		for(i=0; i<notes; i++)
			scanf("%d",&arr[i]);
		for(i=notes-1; i>=0; i--){
			if( collected == need ){
				flag=1;
				break;
			}
			if((arr[i]+collected)>need)
				continue;
			collected+=arr[i];
		}
		(flag==1) ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
