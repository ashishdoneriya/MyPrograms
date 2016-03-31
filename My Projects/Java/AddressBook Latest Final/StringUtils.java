package Address_book;

public class StringUtils{
	public static String UpperLower(String S){
		S=S.trim();
		if(S.length()==0)
			return S;
		int i,j,k;
		int []pos=new int[10];
		pos[0]=0;
		for(i=1,j=1;i<S.length();i++){
			if(S.charAt(i)==' ')
				pos[j++]=i+1;
		}
		StringBuffer S1=new StringBuffer(S.length());
		S1.append(S);
		for(k=0;k<=j-1;k++)
			S1.replace(pos[k],pos[k]+1,(S.charAt(pos[k])+"").toUpperCase());
		return (new String(S1));
	}
//======================================================================
	public static String[] GetCombinations(String S){
		S=S.trim();
		StringBuffer []S1=new StringBuffer[4];
		for(int i=0;i<4;i++){
			S1[i]=new StringBuffer(S.length());
			S1[i].append(S);
		}
		
		S1[0].replace(0,S.length()+1,S.toLowerCase());
		S1[1].replace(0,1,(S.charAt(0)+"").toUpperCase());
		S1[2].replace(0,S.length()+1,UpperLower(S));
		S1[3].replace(0,S.length()+1,S.toUpperCase());
		
		String S2[]=new String [4];
		for(int i=0;i<4;i++){
			S2[i]=new String(S1[i]);
		}
		return (S2);
	}
//======================================================================
	public static boolean IsValidNumber(String S){
		for(int i=0;i<S.length();i++){
			if((S.charAt(i)<'0')||((S.charAt(i)>'9')))
				return false;
		}
		return true;
	}
//======================================================================
	public static boolean IsValidMobile(String S){
		if(S.length()!=10)
			return false;
		for(int i=0;i<S.length();i++){
			if((S.charAt(i)<'0')||((S.charAt(i)>'9')))
				return false;
		}
		return true;
	}
	public static boolean IsValidEmail(String S){
		if(S.indexOf('@')==-1||S.indexOf('.')==-1||S.length()<5)
			return false;
		else if(S.charAt(0)=='@'||S.indexOf("@.")!=-1||S.indexOf(".@")!=-1)
			return false;
		else
			return true;
	}
//======================================================================
/*	public static int Strcmp(String S1, String S2){
		if(S1.equalsIgnoreCase(S2)==true)
			return 0;
		if((S1.length()>S2.length())&&S1.startsWith(S2.toLowerCase())==true)
			return 1;
		else
			return -1;
	}
	*/
	public static int Strcmp(String str1, String str2){
		int l1=str1.length(),l2=str2.length();
		for(int i=0;;i++){
			if(i==l1&&i==l2)
				return 0;
			if(i==l1&&i!=l2)
				return -1;
			if(i!=l1&&i==l2)
				return 1;
			if((str1.toLowerCase()).charAt(i)<(str2.toLowerCase()).charAt(i))
				return -1;
			if((str1.toLowerCase()).charAt(i)>(str2.toLowerCase()).charAt(i))
				return 1;
		}	
	}

//======================================================================
	public static boolean StrcmpAdv(long ph1, long ph2){
		String S1=String.valueOf(ph1);
		String S2=String.valueOf(ph2);
		if(S1.indexOf(S2)==-1)
			return false;
		else
			return true;
	}
//======================================================================
	public static boolean StrcmpAdv(String S1, String S2){
		if((S1.toLowerCase()).indexOf(S2.toLowerCase())==-1)
			return false;
		else
			return true;
	}
}
