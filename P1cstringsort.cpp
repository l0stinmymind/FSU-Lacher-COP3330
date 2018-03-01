int LexDiff (const char* s1, const char* s2)
{
  int diff_value = 0;
  while (*s1 !='\0' && *s2 != '\0')
  {
    char s1_ascii_value;
    char s2_ascii_value;
    if (*s1 == *s2)
    {
      s1++, s2++;
    }
    else
    {
      s1_ascii_value = int (*s1);
      s2_ascii_value = int (*s2);
      diff_value = s1_ascii_value - s2_ascii_value;
      break;
    }
    if (*s1 =='\0' && *s2 == '\0')
    {
      diff_value=0;
      break;
    }
    else
    {
      if (*s1 =='\0')
      {
        diff_value = -99;
        break;
      }
      if (*s2 =='\0')
      {
        diff_value = 99;
        break;
      }

    }
  }
  return diff_value;
}

int  DictionaryDiff (const char* s1, const char* s2)
{
  int diff_value = 0;
  while (*s1 !='\0' && *s2 != '\0')
  {
    char s1_dict_value;
    char s2_dict_value;
    if (*s1 == *s2)
    {
      s1++, s2++;
    }
    else 
    {
      s1_dict_value = int (*s1);
      s2_dict_value = int (*s2);
      if (s1_dict_value <=90)
      {
        s1_dict_value=s1_dict_value+32;
      }
      if (s2_dict_value <=90)
      {
        s2_dict_value=s2_dict_value+32;
      }
      diff_value = s1_dict_value - s2_dict_value;
      break;
    }
    if (*s1 =='\0' && *s2 == '\0')
    {
      diff_value= 0;
      break;
    }
    else 
    {
      if (*s1 =='\0')
      {
        diff_value = -99; 
        break;
      }
      if (*s2 =='\0')
      {
        diff_value = 99;
        break;
      }

    }
  }
  
  if (diff_value<0) 
  {

    diff_value=-1;
  }
  if (diff_value>0) 
  {

    diff_value=1;
  }
  return diff_value;
}

bool LexComp (const char* s1, const char* s2)
{
  bool results;
  if (LexDiff(s1,s2) < 0)
  {
    results = true;
  }
  else
  {
    results = false;
  }
  return results;
}

bool DictionaryComp (const char* s1, const char* s2)
{
  bool results;
  if (DictionaryDiff(s1,s2) < 0)
  {
    results = true;
  }
  else
  {
    results = false;
  }
  return results;
} 

void LexStringSort (char* *beg, char* *end)
{
  if (end - beg < 2) return; 
  char* *i; 
  char* *j; 
  char* *k; 
  char*  t; 
  for (i = beg; i != end; ++i)
  {
    t = *i;
    for (k = i, j = k--; j != beg && LexComp(t,*k); --j, --k) 
      *j = *k;
    *j = t;   
  }
}

void DictionaryStringSort (char* *beg, char* *end)
{
  if (end - beg < 2) return; 
  char* *i; 
  char* *j; 
  char* *k; 
  char*  t; 
  for (i = beg; i != end; ++i)
  {
    t = *i;
    for (k = i, j = k--; j != beg && DictionaryComp(t,*k); --j, --k) 
      *j = *k;
    *j = t;   
  }
}
