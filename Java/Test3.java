int util::strcomp(const char *str1, const char *str2){
	for(int i=0;;i++){
		if(str1[i]=='\0'&&str2[i]=='\0')
			return 0;
		if(str1[i]=='\0'&&str2[i]!='\0')
			return -1;
		if(str1[i]!='\0'&&str2[i]=='\0')
			return 1;
		if((toupper(str1[i])!=toupper(str2[i]))&&(toupper(str1[i])!=tolower(str2[i]))&&(tolower(str1[i])!=toupper(str2[i]))&&(tolower(str1[i])!=tolower(str2[i])))
			return -1;
	}
}


	public boolean Strcomp(String str1, String str2){
		byte ch1[]=str1.getBytes();
		byte ch2[]=str2.getBytes();
		int l1=ch1.length;
		l2=ch2.length;
		for(int i=0;;i++){
			if(i==l1&&i==l2)
				return true;
			if(i==l1&&i!=l2)
				return false;
			if(i!=l1&&i==l2)
				return true;
			if(((str1.charAt(i))+"").toLowerCase()!=((str2.charAt(i))+"").toLowerCase())
				return false;
		}	
	}
