#include<stdio.h>
#include<stdlib.h>

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *start4 = NULL;
struct node *start5 = NULL;
struct node *header1;
struct node *header2;
struct node *header3;
struct node *header4;
struct node *header5;

struct node
{
    int seat;
    struct node *next;
};

//Creating a Linked List (Creating Seats for each movie)
struct node *create_ll(struct node *start,int data,struct node *header)
{
         struct node *new_node, *ptr;
    
new_node = (struct node*)malloc(sizeof(struct node));
new_node -> seat=data;
if(start==NULL)
{
    header->next=new_node;
    header->seat++;
    new_node -> next = NULL;
    start = new_node;
}
else
{
    header->next=start;
    header->seat++;
    ptr=start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next = new_node;
    new_node->next=NULL;
}

return start;
}

//Displaying the linked list(Displaying the number of seats Available)
struct node *display(struct node *start,struct node *header)
{
struct node *ptr;
ptr = start;
    printf("\n--------------------Screen--------------------\n");
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
             printf("\t %d", ptr -> seat);
             ptr = ptr -> next;
        }
        printf("\n");
    }
    printf("-------------------------------------------------\n");
    printf("\nSeats Available= %d\n",header->seat);
   
return start;
}

//Displaying the movie ticket booked
void tickets_booking(int arr[],int len,char film[])
{
    char name[10];
    long phone,id=7572;
    printf("Enter your name\n");
    scanf("%s",name);
    printf("Enter phone number\n");
    scanf("%ld",&phone);
    printf("\n\n*****************************************************\n");
    printf("--------------------Movie Ticket--------------------\n");
    printf("\t\t%s\n",film);
    printf("Booking id = AB%ld\t\t\t\t",id);
    printf("Number of seats = %d\n",len);
    
    printf("Name = %s\t\t\t\t",name);
    printf("Seat numbers = ");
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");
    
    printf("Phone number = %ld\t\t",phone);
    printf("Price = Rs %d\n",(len*300));
    printf("Timing = 7:30 p.m\n");
    printf("Date = 1/2/2022\n");
    printf("Venue = PVR Koramangala,Gold Cinemas,Bangalore\n");
    
    printf("*********************************************************\n");
}

//Delete at a given position(Booking seat)
struct node *delete_pos(struct node *start,struct node *header,char moviearr[])
{
    struct node *ptr;
    int pos,x=1,len=0,seats;
    ptr=start;
    
    printf("Enter the number of seats to be booked\n");
    scanf("%d",&seats);
    int seat[seats];
    
    while(ptr!=NULL)
    {
        len++;
        ptr=ptr->next;
    }
   
    for(int k=0;k<seats;k++)
    {
        pos=0;
        x=1;
        ptr=start;
    printf("Enter the position at which the seat is to be taken\n");
    scanf("%d",&pos);
        seat[k]=pos;
    
     if(pos>len || pos<0)
        printf("Invalid position \n");
    else
    {
    while(x!=pos)
    {
        ptr=ptr->next;
        x++;
    }
   
        ptr->seat='\0';
        header->seat--;
    }
    }
    if(seats>0)
    tickets_booking(seat,seats,moviearr);
    
    return start;
}



//Searching a key element in the list(Re adding the seat when its cancelled)
struct node *searching(struct node *start,struct node *header)
{
    struct node *ptr;
    int key=0,pos=1;
    if(start!=NULL)
    {
    ptr=start;
    printf("Enter the seat number to cancel\n");
    scanf("%d",&key);
    while(pos!=key)
    {
        ptr=ptr->next;
        pos++;
    }
        if(ptr->seat==0)
        {
            ptr->seat=key;
        printf("Refund is initiated\n");
            header++;
        }
           else
            printf("This Seat is not booked\n");
    }
    return start;
}

//Main function
int main()
{
    
    header1=(struct node *)malloc(sizeof(struct node));
    header2=(struct node *)malloc(sizeof(struct node));
    header3=(struct node *)malloc(sizeof(struct node));
    header4=(struct node *)malloc(sizeof(struct node));
    header5=(struct node *)malloc(sizeof(struct node));
    
    header1->seat=0;
    header1->next=NULL;
    header2->seat=0;
    header2->next=NULL;
    header3->seat=0;
    header3->next=NULL;
    header4->seat=0;
    header4->next=NULL;
    header5->seat=0;
    header5->next=NULL;

    int i;
    char movie[][30]={"Avengers Endgame","Thor","Iron man","Captain America","Spiderman - No way home"};
    
    for(i=1;i<101;i++)
    {
        start1=create_ll(start1,i,header1);
        start2=create_ll(start2,i,header2);
        start3=create_ll(start3,i,header3);
        start4=create_ll(start4,i,header4);
        start5=create_ll(start5,i,header5);
    }
    
    int ch,ch1,ch2;
    printf("*****Tickets Booking Menu*****\n");
    printf("1.Movie Details\n");
    printf("2.Number of Seats Avaliable\n");
    printf("3.Book ticket\n");
    printf("4.Cancel Ticket\n");
    
    printf("0.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    while(ch!=0)
    {
    switch (ch)
    {
        case 1 : printf("*****Movie Details*****\n");
            printf("1.Avengers Endgame\n");
            printf("After Thanos, an intergalactic warlord, disintegrates half of the universe, the Avengers must reunite and assemble again to reinvigorate their trounced allies and restore balance.\n\n");
            
            printf("2.Thor\n");
            printf("The Thor film series is a run of four movies (so far) set in the Marvel Cinematic Universe consisting of Thor, Thor: The Dark World, Thor: Ragnarok and the currently-in-development Thor: Love and Thunder. The series is anchored by Chris Hemsworth as Thor, Tom Hiddleston as Loki and Natalie Portman as Jane Foster.\n\n");
            
            printf("3.Iron Man\n");
            printf("When Tony Stark, an industrialist, is captured, he constructs a high-tech armoured suit to escape. Once he manages to escape, he decides to use his suit to fight against evil forces to save the world.\n\n");
            
            printf("4.Captain America\n");
            printf("During World War II, Steve Rogers decides to volunteer in an experiment that transforms his weak body. He must now battle a secret Nazi organisation headed by Johann Schmidt to defend his nation.\n\n");
            
            printf("5.Spiderman - No way home\n");
            printf("With Spider-Man's identity now revealed, our friendly neighborhood web-slinger is unmasked and no longer able to separate his normal life as Peter Parker from the high stakes of being a superhero. When Peter asks for help from Doctor Strange, the stakes become even more dangerous, forcing him to discover what it truly means to be Spider-Man.\n\n");
            break;
            
        case 2 : printf("\n*****Number of Seats Avaliable*****\n");
            printf("1.Avengers Endgame\n");
            printf("2.Thor\n");
            printf("3.Iron Man\n");
            printf("4.Captain America\n");
            printf("5.Spiderman - No way home\n");
            printf("Enter your choice\n");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1 : printf("Seats Available = %d\n",header1->seat);
                    break;
                case 2 : printf("Seats Available = %d\n",header2->seat);
                    break;
                case 3 : printf("Seats Available = %d\n",header3->seat);
                    break;
                case 4 : printf("Seats Available = %d\n",header4->seat);
                    break;
                case 5 : printf("Seats Available = %d\n",header5->seat);
                    break;
                default : printf("Wrong choice\n");
            }
            break;
            
        case 3 : printf("\n*****Book Tickets*****\n");
            printf("1.Avengers Endgame\n");
            printf("2.Thor\n");
            printf("3.Iron Man\n");
            printf("4.Captain America\n");
            printf("5.Spiderman - No way home\n");
            printf("Enter your choice\n");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1 : start1=display(start1, header1);
                    start1=delete_pos(start1, header1,movie[0]);
                    break;
                case 2 : start2=display(start2, header2);
                    start2=delete_pos(start2, header2,movie[1]);
                    break;
                case 3 : start3=display(start3, header3);
                    start3=delete_pos(start3, header3,movie[2]);
                    break;
                case 4 : start4=display(start4, header4);
                    start4=delete_pos(start4, header4,movie[3]);
                    break;
                case 5 : start5=display(start5, header5);
                    start5=delete_pos(start5, header5,movie[4]);
                    break;
            }
            break;
                    
                case 4 : printf("\n*****Cancel Tickets*****\n");
                    printf("1.Avengers Endgame\n");
                    printf("2.Thor\n");
                    printf("3.Iron Man\n");
                    printf("4.Captain America\n");
                    printf("5.Spiderman - No way home\n");
                    printf("Enter your choice\n");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1 :  start1=searching(start1, header1);
                            break;
                        case 2 :  start2=searching(start2, header2);
                            break;
                        case 3 :  start3=searching(start3, header3);
                            break;
                        case 4 :  start4=searching(start4, header4);
                            break;
                        case 5 :  start5=searching(start5, header5);
                            break;
                        default : printf("Invalid choice\n");
                    }
            
    }
        printf("\n*****Tickets Booking Menu*****\n");
        printf("1.Movie Details\n");
        printf("2.Number of Seats Avaliable\n");
        printf("3.Book ticket\n");
        printf("4.Cancel Ticket\n");
        
        printf("0.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
    }

    return 0;
}




