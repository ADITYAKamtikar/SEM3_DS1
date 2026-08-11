// Online C compiler to run C program online
#include <stdio.h>

struct student{
    char name[100];
    int roll_no;
    float marks;
};


int acceptstudent(struct student s[50], int size){
    for(int i = 0; i < size; i++){
        printf("enter the name of student:\n");
        scanf("%s", s[i].name); 
        
        printf("enter the Roll No:\n");
        scanf("%d", &s[i].roll_no); 
        
        printf("enter the marks:\n");
        scanf("%f", &s[i].marks); 
    }
    return 0; 
}

int displaystudents(struct student s[50],int size){
    printf("name\troll_no\tmarks\n");
    for(int i=0;i<size;i++){
        printf("%s\t%d\t%.2f\n",s[i].name,s[i].roll_no,s[i].marks);
    }
    return 0;
}

int linearsearch(struct student s[50],int size,int key){
    for(int i=0;i<size;i++){
        if(s[i].roll_no==key){
            return i;
        }
    }
    return -1;
}

int bubble_sort(struct student copy[50],int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(copy[j].roll_no>copy[j+1].roll_no){
                temp = copy[j].roll_no;
                copy[j].roll_no = copy[j+1].roll_no;
                copy[j+1].roll_no = temp;
            }
            
        }
    }
}

int binary_search(struct student copy[50],int size,int key){
    
    int low=0;
    int high = size-1;
    while(low<=high){
        int mid = (high+low)/2;
        if(copy[mid].roll_no==key){
            return mid;
        }
        else if(copy[mid].roll_no<key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int selection_sort(struct student copy[50],int size){
    int min;
    int temp;
    for(int i=0;i<size-1;i++){
        min = i;
        for(int j=i+1;j<size;j++){
            
            if(copy[j].roll_no<copy[min].roll_no){
                min=j;
            }
        }
        if(min!=i){
            temp = copy[i].roll_no;
            copy[i].roll_no = copy[min].roll_no;
            copy[min].roll_no = temp;
        }
    }
    
}

void insertion_sort(struct student copy[50], int size)
{
    int key;
    int j;

    for (int i = 1; i < size; i++)
    {
        key = copy[i].roll_no;
        j = i - 1;
        while (j >= 0 && copy[j].roll_no > key)
        {
            copy[j + 1].roll_no = copy[j].roll_no;
            j--;
        }
        copy[j + 1].roll_no = key;
    }
}


void shell_sort(struct student copy[], int size)
{
    int temp;
    for (int gap = size / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < size; i++)
        {
            temp = copy[i].roll_no;
            int j = i;
            while (j >= gap &&
                   copy[j - gap].roll_no > temp)
            {
                copy[j].roll_no = copy[j - gap].roll_no;
                j = j - gap;
            }
            copy[j].roll_no = temp;
        }
    }
}



int main() {
    // Write C code here
    struct student s[50];
    struct student copy[50];
    int size;
    printf("enter the number of student data:\n");
    scanf("%d",&size);
    printf("enter students detail:\n");
    acceptstudent(s,size);
    printf("displaying student details:\n");
    displaystudents(s,size);
    int key;
    for (int i = 0; i < size; i++) {
    copy[i] = s[i];
}
    int choice;
    int result;
    do{
    printf("enter your choice:\n");
    printf("enter 1 for linear search\nenter 2 for bubble sort\nenter 3 for binary search\nenter 4 for selection sort\n enter 5 for insertion sort\n enter 6 for shell sort\n 7 to exit\n");
    scanf("%d",&choice);
    switch(choice){
        
        case 1:{
            printf("enter the roll no to be found:\n");
            scanf("%d",&key);
            result = linearsearch(s,size,key);
            if(result!=-1) {
                printf("Student found at index %d\n", result);
                printf("Name: %s, Marks: %.2f\n", s[result].name,s[result].marks);
            } 
            else{
                printf("Student with Roll No %d not found.\n", key);
            }
            break;
        }
        
        case 2:
            bubble_sort(copy,size);
             for (int i = 0; i < size; i++)
            {
                printf("%s %d %.2f\n",
               copy[i].name, copy[i].roll_no, copy[i].marks);
            }
            break;
        
        case 3:
             printf("enter the roll no to be found:\n");
             scanf("%d",&key);
            bubble_sort(copy,size);
            result = binary_search(copy,size,key);
            if(result!=-1){
                printf("found at %d",result);
            }
            else{
                printf("not found in the database");
            }
            break;
        case 4:
            selection_sort(copy,size);
            displaystudents(copy,size);
            break;
        case 5:
            insertion_sort(copy,size);
            displaystudents(copy,size);
            break;
        case 6:
            shell_sort(copy,size);
            displaystudents(copy,size);
            break;
        case 7:
            break;
    }
    }while(choice!=7);
    
    
}