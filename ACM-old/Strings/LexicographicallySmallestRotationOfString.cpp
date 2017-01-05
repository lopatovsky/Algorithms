memcpy( str+len, str, len );
int i = 0;
int j = 1;
int k = 0;
// len = strlen(str);
while (i < len && j < len && k < len)
{
  if (str[i+k] == str[j+k])
    ++k;
  if (str[i+k] > str[j+k])
  {
    i = max(i+k+1, j+1);
    k = 0;
  }
  else if (str[i+k] < str[j+k])
  {
    j = max(j+k+1, i+1);
    k = 0;
  }
}
printf("%d\n", min(i,j)+1);