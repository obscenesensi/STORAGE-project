void reverse(char *str)
{   
    char *end=str;
    char temp;
    if(str)
    {
        while(*end)
            end++;
        end--;
        while(str<end)
        {
            temp=*str;
            *str++=*end;
            *end--=temp;
        }
    }
}
