#include <stdio.h>

struct product
{
int product_id;
int product_qty;
char item_name[20];
float price;
};

int main()
{
    struct product p[10]={
{101,5,"h&m",1000.0},
{102,4,"gucci",2000.0},
{103,3,"us polo",3000.0},
{104,2,"pe",4000.0},
{105,6,"lv",5000.0},
{106,3,"armani",6000.0},
{107,4,"zara",5000.0},
{108,8,"adidas",2500.0},
{109,3,"chanel",4500.0},
{110,7,"d&g",3500}
    };
int choice;


do{
printf("\t\t\t=====TREND INVOICE=====\t\t\t\n");
printf("\t\t\t\tmenu\t\t\t\t\n");
printf("\t\t\t1.view inventory stock\n");
printf("\t\t\t2.purchase item\n");
printf("\t\t\t3.checkout & exit\n");
printf("enter your choice");
scanf("%d",&choice);
while(choice<1||choice>3)
{
    printf("invalid choice\n");
    scanf("%d",&choice);
if(choice>=1 && choice<=3)
break;
}
if(choice==1)
{
    //display stock available
printf("------------------------------------------------------------------------\n");
printf("\n item_name\t\tproduct_id\t\tproduct_qty\t\tprice\n");
printf("------------------------------------------------------------------------\n");

    for(int i=0;i<10;i++)
    {
        printf("%s\t\t\t%d\t\t\t%d\t\t\t%.2f\n",p[i].item_name,p[i].product_id,p[i].product_qty,p[i].price);
    }

}
else if(choice==2)
{
    //purchase item
   int id_input;
    printf("enter product_id  to purchase");
    scanf("%d", &id_input);
    
for(int i=0;i<sizeof(p)/sizeof(p[0]);i++)
{
    if(p[i].product_id==id_input)
        {
       int input_qty;
       printf("enter quantity to purchase");
        scanf("%d", &input_qty);
            if(p[i].product_qty>=input_qty)
            {
      float amount=p[i].price*input_qty;
                printf("item is available\n");
                printf("item name: %s\n",p[i].item_name);
                printf("quantity purchased: %d\n",input_qty);
                printf("amount:%.2f\n",amount);
            }
            else 
                (p[i].product_qty<input_qty);
            {
                printf("out of stock\n");
            }
               p[i].product_qty=p[i].product_qty-input_qty;
                printf("remaining quantity : %d\n",p[i].product_qty);
        }
            // break;
        
}
}
else if(choice==3)
{
    //checkout and exit
printf("thank you for shopping \n");
}
else
break;
}while(choice!=3);

return 0;
}