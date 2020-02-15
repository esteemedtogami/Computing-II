char* reverse(char array[]);

char* reverse(char array[])
{
    int size = 0, i = 0, j = 0;
    
    while (array[size] != '\0')
    {
        ++size;
    }
    
    char backward[size - 1];
    
    while (i < size)
    {
        backward[i] = array[i];
        i++;
    }
    
    i -= 1;
    
    while (i >= 0)
    {
        array[j] = backward[i];
        j ++;
        i --;
    }
    
    return array;
}