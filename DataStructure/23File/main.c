#include <stdio.h>
#include <string.h>

//FILE结构的具体实现，
struct FILE_pointer {
    char *_ptr;      //下一个读取的字符地址，会随着读取的字符自动前移
    int _cnt;        //剩余的字符
    char *_base;     //缓冲区基地址（起始地址）
    int _flag;       //记录读写权限
    int _file;       //（唯一）文件描述符，提供给操作系统以区分文件
    int _charbuf;
    int _bufsiz;     //缓冲区大小
    char *_tmpfname;
};

int file_open(){
    FILE *fp;
    //打开文件，返回关联该文件的指针
    fp=fopen("file.txt", "r+");
    if(NULL==fp){
        perror("fopen failed");//定位失败原因
        return -1;
    }

    //文件的基本读写
    char output;
    while((output=fgetc(fp))!=EOF)
        putchar(output);

    putchar('\n');

    char input;
    input=fputc('H',fp);
    if(-1==input){
        perror("fputc");
        return -1;
    }

    return 0;
}

int file_read(){

    FILE *fp2;
    fp2=fopen("file2", "rb+");
    if(NULL==fp2){
        perror("fopen");
        return -1;
    }
    int ret;


    char buffer[20]="hello\nworld";

//    ret= fwrite(buffer, sizeof(char), strlen(buffer), fp2);

//    char buffer1[20]={0};
//    ret= fread(buffer1, sizeof(char), sizeof(buffer1), fp2);


    int i=123456;
    ret=fwrite(&i,sizeof(int), 1,fp2);

    i=0;
    fread(&i, sizeof(int), 1,fp2);
    printf("%d", i);

    return 0;
}

int file_fgets(){
    FILE *fp3;
    fp3=fopen("file3.txt", "rb+");
    if(NULL==fp3){
        perror("fopen");
        return -1;
    }

    //一次读取一行
    char buffer[20]={0};
    while(fgets(buffer, sizeof(buffer), fp3)!=NULL)
        printf("%s", buffer);

    return 0;
}

int main() {
    FILE *fp4;
    fp4=fopen("file4.txt", "rb+");
    if(NULL==fp4){
        perror("fopen");
        return -1;
    }

    char str[20]="hello\nworld";
    int len= strlen(str);
    long pos;

    int ret;

    fwrite(str, sizeof(char), len, fp4);

    ret=fseek(fp4, -5,SEEK_CUR);

    if(ret!=0){
        perror("fseek");
        fclose(fp4);
        return -1;
    }

    pos= ftell(fp4);
    printf("pos=%ld\n", pos);

    memset(str, 0, sizeof(str));
    fread(str,sizeof(char), sizeof(str), fp4);

    printf("str=%s\n",str);

    return 0;
}
