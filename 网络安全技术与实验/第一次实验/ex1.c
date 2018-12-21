//请填空，使程序运行结果为：打印"why u r here?!"

void why_here(void)
{    printf("why u r here?!\n"); 
      exit(0); 
}

void f()
{     int buff[1]; int * p = &buff; 
       buff[2]= (int)why_here;
}

int main(int argc, char * argv[])
{      f();
       return 0;
}
