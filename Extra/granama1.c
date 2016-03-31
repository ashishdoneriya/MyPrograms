#include<stdio.h>
int main() {
	int T, flagG, flagC, i;
	char R[26] = {0},  S[26] = {0};
	char strR[30],  strS[30];
	scanf("%d", &T);
	while(T--) {
		scanf("%s %s", strR, strS);
		for(i = 0;strR[i] != 0;i++)
			R[strR[i] - 91]++;
		for(i = 0;strS[i] != 0;i++)
			S[strS[i] - 91]++;
	
		//If granama or not
		for(i = 0, flagG = 1; i<26; i++) {
			if(R[i] == S[i])
				continue;
			else{
				flagG=0;
				break;
			}
		}
		//for chef
		for(i = 0, flagC = 1; i < 26; i++) {
			if((R[i] != 0 && S[i] != 0) || (R[i] == 0 && S[i] == 0))
				continue;
			flagC = 0;
			break;
		}
		if(flagG == flagC)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

