void computeLPS(string pat, vector<int>& lps){
	int M = pat.length();
	int len = 0; //length of previous longest prefix & suffix
	
	lps[0] = 0; //because there is no proper prefix or suffix of pat[0...0]
	
	int i = 1;
	while(i < M){
	  if(pat[i] == pat[len]){
		  len++;
		  lps[i] = len;
		  i++;
	  }
	  else{
		  if(len != 0){
			  len = lps[len - 1];
		  }
		  else{
			  lps[i] = 0;
			  i++;
		  }
	  }
	}
}

vector<int> searchKMP(string pat, string txt){
	int N = txt.length();
	int M = pat.length();
	vector<int> result; //stores the indices of txt which contains pat as a substring
	
	//create an LPS array to store the longest proper prefix which is also a suffix
	//lps[i] = the longest proper prefix of pat[0...i] which is also a suffix of pat[0...i]
	vector<int> lps(M, 0);
	computeLPS(pat, lps);
	
	int i = 0; //index for txt
	int j = 0; //index for pat
	
	while(i < N){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}
	
		if(j == M){ //found
			result.push_back(i - j); //if 1-based indexing, push back (j - i + 1) to result vector
			j = lps[j - 1];
		}
		
		else if(i < N && txt[i] != pat[j]){
			if(j != 0)
				j = lps[j - 1];
			else 
				i++;
		}
	}
	
	return result;
}
