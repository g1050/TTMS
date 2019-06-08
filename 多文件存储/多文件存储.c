#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/io.h>
//学生结构体
typedef struct 
{
    long ID;
    char  num[10];
    char name[30];
}student_t;

//课程结构体
typedef struct
{
    long ID;
    char name[30];
    int credit;
}course_t;

//成绩结构体
typedef struct
{
    long ID;
    long stuID;
    long courID;
    int score;
}score_t;

//存储业务数据主键的结构体
typedef struct
{
    char name[41];
    long key;
}entity_key_t;

const char *file_student = "student.dat";//学生文件名
const char *file_course = "course.dat";//课程文件名
const char *file_score = "score.dat";//成绩文件名
const char *file_key = "key.dat";//主键文件名
const char *file_name_tmp = "tmp.dat";//删除时用的临时变量名字 

int Score_Add(score_t *ptScore);//在成绩中添加一个新成绩ptScore*
int Student_IsExist(long stuID);//判断学生是否存在
int Course_IsExist(long courID);//判断课程是否存在
long GetNewKey(const char *entName)//为业务数据分配主键
{
    entity_key_t ent;
    FILE *fp;
    int found = 0;
    long newEntKey = 1;
    if(access(file_key,0)) //判断文件是否存在
    {
        if(!(fp = fopen(file_key,"wb+"))) //新建文件
        {
            return 0;
        }
    }
    else
    {
        fp = fopen(file_key,"rb+"); //以读写方式打开
        if(!fp)    return 0;
    }

    while(fread(&ent,sizeof(entity_key_t),1,fp) == 1)
    {
        if(0 == strcmp(ent.name,entName))//匹配业务数据名
        {
            fseek(fp,-(int)sizeof(entity_key_t),SEEK_CUR);
            ent.key++;
            newEntKey = ent.key;
            fwrite(&ent,sizeof(entity_key_t),1,fp);
            found = 1;
            break;
        }
    }
    if(!found) //未找到业务数据
    {
        strcpy(ent.name,entName);
        ent.key = 1;
        fwrite(&ent,sizeof(entity_key_t),1,fp);
    }

    fclose(fp);
    return newEntKey;
    
}

void Student_InitFile(void)
{
    student_t stu_data[] = {{1,"001","stu_1"},{0,"002","stu_2"},{0,"003","stu_3"}};
    FILE *fp_stu = fopen(file_student,"wb");
    if(!fp_stu)
    {
        printf("打开失败!\n");
        return ;
    }

    for(int i = 0;i<3;i++)
        stu_data[i].ID = GetNewKey("student"); //使用student分配主键
    fwrite(stu_data,sizeof(student_t),3,fp_stu);
    fclose(fp_stu);
}

void Course_InitFile()
{
    course_t cour_data[] = {{0,"Language",4},{0,"Advanced Mathmatics",6}};
    FILE *fp_cour = fopen(file_course,"wb");
    if(!fp_cour)
    {
        printf("打开失败\n");
        return ;
    }
    for(int i = 0;i<2;i++) 
        cour_data[i].ID = GetNewKey("course"); //为course分配主键
    fwrite(cour_data,sizeof(course_t),2,fp_cour);
    fclose(fp_cour);
}

void Student_PrintAll()//打印输出所有学生数据
{
    student_t stu_tmp;
    FILE *fp = fopen(file_student,"rb");
    if(!fp)
    {
        printf("打开失败!\n");
        return ;
    }

    printf("学生文件中的数据为:\n");
    while(fread(&stu_tmp,sizeof(student_t),1,fp) == 1)
    {
        printf("---------------------------------\n");
        printf("ID : %ld\n",stu_tmp.ID);
        printf("num : %s\n",stu_tmp.num);
        printf("name : %s\n",stu_tmp.name);
        printf("---------------------------------\n");

    }
}

void Course_PrintAll()
{
    course_t cour_tmp;
    FILE *fp = fopen(file_course,"rb");
    if(!fp)
    {
        printf("课程文件打开失败\n");
        return ;
    }

    printf("课程文件中的数据为:\n");
    while(fread(&cour_tmp,sizeof(course_t),1,fp) == 1)
    {

        printf("---------------------------------\n");
        printf("ID  = %ld\n",cour_tmp.ID);
        printf("name = %s\n",cour_tmp.name);
        printf("credit = %d\n",cour_tmp.credit);
        printf("---------------------------------\n");
    }
    return ;
}

void Score_InitFile()
{
    score_t score;
    while(1)
    {
        printf("请输入学生ID,课程ID和成绩(输入０表示退出)\n");
        scanf("%ld",&(score.stuID));
        if(score.stuID == 0) break;
        scanf("%ld %d",&(score.courID),&(score.score));
        if(Student_IsExist(score.stuID) && Course_IsExist(score.courID))
        {
            Score_Add(&score);
        }
        else
        {
            printf("数据输入有误!\n");
        }
    }
}
int Score_Add(score_t *ptScore) //在成绩文件中添加一个新成绩　PtrScore
{
    int rtn = 0;
    ptScore->ID = GetNewKey("score"); //通过业务数据名分配新主键
    FILE *fp_sco = fopen(file_score,"ab");
    if(!fp_sco)
    {
        printf("文件打开失败\n");
        return 0;
    }
    rtn = fwrite(ptScore,sizeof(score_t),1,fp_sco);
    fclose(fp_sco);
    return rtn;
}

int Student_IsExist(long stuID) //检测ＩＤ为stuID的学生是否存在，存在则返回１
{
    int found = 0;
    student_t stu_tmp;
    FILE *fp = fopen(file_student,"rb");
    if(!fp)
    {
        printf("打开失败！\n");
        return 0;
    }
    while(fread(&stu_tmp,sizeof(student_t),1,fp) == 1)
    {
        if(stu_tmp.ID == stuID)
        {
            found = 1;
            break;
        }
    }

    fclose(fp);
    return found;
}

int Course_IsExist(long courID)//判断课程是否存在
{
    int found = 0;
    course_t cour_tmp;
    FILE *fp = fopen(file_course,"rb");
    if(!fp)
    {
        printf("课程文件打开失败!\n");
        return 0;
    }
    while(fread(&cour_tmp,sizeof(course_t),1,fp) == 1)
    {
        if(cour_tmp.ID == courID)
        {
            found = 1;
        }
    }
    return found;
}

int Student_GetByID(long stuID,student_t *stu)
{
    student_t stu_tmp;
    FILE *fp = fopen(file_student,"rb");
    if(!fp)
    {
        printf("studnet_GetById中学生文件打开失败!\n");
        return 0;
    }
    while(fread(&stu_tmp,sizeof(student_t),1,fp) == 1)
    {
        if(stu_tmp.ID == stuID)
        {
            *stu = stu_tmp;
            return 1;
        }
    }
    return 0;
}

int  Course_GetByID(long courID,course_t *cour)
{
   course_t cour_tmp;
   FILE *fp = fopen(file_course,"rb");
   if(!fp)
   {
       printf("Course_GetByID中课程文件打开失败!\n");
       return 0;
   }
   while(fread(&cour_tmp,sizeof(course_t),1,fp) == 1)
   {
        if(cour_tmp.ID == courID)
        {
            *cour = cour_tmp;
            return 1;
        }
   }

   return 0;
}

void Score_PrintAll(void) //以表格形式打印输出成绩文件中的所有成绩数据
{
    score_t sco;
    student_t stu;
    course_t cour;
    int i,count = 0;
    FILE *fp = fopen(file_score,"rb");
    if(!fp)
    {
        printf("打开失败！\n");
        return ;
    }

    printf("成绩文件中的数据为：\n");
    for(i = 0;i<95;i++)
    {
        putchar('=');
    }

    printf("\n%15s|%15s|%15s|%25s|%10s|%10s|\n","Student ID","Student num","Student Name","Course Name","Score","Credit");

    for(i = 0;i<95;i++)
    {
        putchar('=');
    }
    putchar('\n');

    while(fread(&sco,sizeof(score_t),1,fp) == 1)
    {
        //根据ID获取对应学生和课程
        if(!Student_GetByID(sco.stuID,&stu) || !Course_GetByID(sco.courID,&cour))
        {
            printf("找不到数据出错！\n");
            break;
        }
        printf("%15ld|%15s|%15s|%25s|%10d|%10d\n",stu.ID,stu.num,stu.name,cour.name,sco.score,cour.credit);//int 和　long int 矛盾
        count++;
    }
    fclose(fp);
    for(i = 0;i<95;i++)
    {
        putchar('=');
    }

    printf("总共%d条记录",count);
}

void Student_PrinAll()
{
    student_t stu_tmp;
    int count = 0;
    FILE *fp = fopen(file_student,"rb");
    if(!fp)
    {
        printf("Student_PrinAll中学生文件打开失败!\n");
        return ;
    }

    printf("==============================\n");
    while(fread(&stu_tmp,sizeof(student_t),1,fp) == 1)
    {
        printf("ID : %ld\n",stu_tmp.ID);
        printf("num : %s\n",stu_tmp.num);
        printf("name : %s\n",stu_tmp.name);
        count++; 
    }
    printf("==============================\n");
    printf("共计%d条记录!\n",count);
}

int Student_Delete(long stuID)
{
    student_t stu_tmp;
    int count = 0;
    FILE *fp = fopen(file_student,"rb");
    FILE *fp_tmp = fopen(file_name_tmp,"wb");
    if(!fp || !fp_tmp)
    {
        printf("Student_Delete中文件打开失败!\n");
        return -1;
    }
    while(1)
    {
        
        if(fread(&stu_tmp,sizeof(student_t),1,fp) < 1) break;
        if(stu_tmp.ID != stuID)
        {
            fwrite(&stu_tmp,sizeof(student_t),1,fp_tmp);
            
        }
        else
        {
            count++;
        }
    }
    fclose(fp);
    fclose(fp_tmp);
    remove(file_student);
    rename(file_name_tmp,file_student);
    /* FILE *fp2 = fopen(file_student,"rb"); */
    /* if(!fp) printf("打开失败!\n"); */
    /* while(fread(&stu_tmp,sizeof(student_t),1,fp2) == 1) */
    /* { */
    /*     printf("ID :%ld\n",stu_tmp.ID); */
    /*     printf("name :%s\n",stu_tmp.name); */
    /* } */
    return count;
}

int Score_DelbyStuID(long stuID)//删除成绩为stuID的所有学生的成绩
{
    score_t sco_tmp;
    int count = 0;
    FILE *fp = fopen(file_score,"rb");
    FILE *fp_tmp = fopen(file_name_tmp,"wb");
    if(!fp || !fp_tmp)
    {
        printf("Student_GetByID中文件打开失败!\n");
        return -1;
    }
    while(fread(&sco_tmp,sizeof(sco_tmp),1,fp))
    {
       if(sco_tmp.ID != stuID)
       {
            fwrite(&sco_tmp,sizeof(score_t),1,fp_tmp);
       }
       else
       {
           count++;
       }
    }
    fclose(fp);
    fclose(fp_tmp);
    remove(file_score);
    rename(file_name_tmp,file_score);
    return count;
}
int main()
{
    setvbuf(stdout,NULL,_IONBF,0); //取消标准输出缓冲区
    remove(file_key);
    remove(file_score);
    remove(file_course);
    Student_InitFile(); //初始化学生文件
    Course_InitFile();  //初始化课程文件
    Student_PrinAll(); //打印所有学生数据
    Course_PrintAll(); //打印输出所有课程数据 
    Score_InitFile(); //初始化成绩文件
    Score_PrintAll(); //打印输出所有课程数据
    
    long ID;
    printf("\n请输入要删除学生的ID:");
    scanf("%ld",&ID);
    if(Student_Delete(ID))//删除学生数据
    {
        Score_DelbyStuID(ID); //为保证数据一致行性，删除该学生的成绩
        Score_PrintAll();//输出删除后的所有学生数据
    }
    return 0;
}

