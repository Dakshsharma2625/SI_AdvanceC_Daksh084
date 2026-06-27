#include<stdio.h>
#include<string.h>

struct Inventory
{
    int ID;
    int MRP;
    int stock;
    int offer;
    char name[20];
};

int main()
{
    int choice;
    int i,j;

    struct Inventory item[10] =
    {
        {1,990,40,90,"Apple"},{2,1990,60,130,"Mango"},
        {3,2990,90,40,"Banana"},
        {4,3990,40,550,"Grapes"},{5,4990,50,500,"Eggs"},{6,5990,70,330,"Watermelon"},{7,6990,80,440,"Guava"},
        {8,7990,360,650,"Veggies"},{9,8990,330,560,"Pizza"},
        {10,9990,100,650,"Blades"}
    };

    int purchase;
    int k=0;
    int total=0;
    int quantity=0;
    int found;
    int role;
    int newVal;

    int cartID[10];
    int cartQty[10];
    int cartTotal[10];
    int cartCount=0;
    int grandTotal=0;

    printf("\n========= Trend Mart =========\n");
    printf("1. Owner\n");
    printf("2. Customer\n");
    printf("Enter Role: ");
    scanf("%d",&role);

    if(role==1)
    {
        do
        {
            printf("\n------- Owner Panel -------\n");
            printf("1. View Inventory\n");
            printf("2. Update Stock\n");
            printf("3. Update MRP\n");
            printf("4. Update Offer\n");
            printf("5. Update Product Name\n");
            printf("6. Exit\n");
            printf("Enter Choice: ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                    printf("\nID\tName\t\tMRP\tStock\tOffer\n");
                    for(i=0;i<10;i++)
                    {
                        printf("%d\t%-12s\t%d\t%d\t%d\n",
                               item[i].ID,
                               item[i].name,
                               item[i].MRP,
                               item[i].stock,
                               item[i].offer);
                    }
                    break;

                case 2:
                    printf("Enter Product ID: ");
                    scanf("%d",&purchase);
                    found=0;
                    for(j=0;j<10;j++)
                    {
                        if(item[j].ID==purchase)
                        {
                            found=1;
                            printf("Current Stock: %d\n",item[j].stock);
                            printf("Enter New Stock: ");
                            scanf("%d",&newVal);
                            item[j].stock=newVal;
                            printf("Stock Updated!\n");
                            break;
                        }
                    }
                    if(found==0)
                    {
                        printf("ID Not Found\n");
                    }
                    break;

                case 3:
                    printf("Enter Product ID: ");
                    scanf("%d",&purchase);
                    found=0;
                    for(j=0;j<10;j++)
                    {
                        if(item[j].ID==purchase)
                        {
                            found=1;
                            printf("Current MRP: %d\n",item[j].MRP);
                            printf("Enter New MRP: ");
                            scanf("%d",&newVal);
                            item[j].MRP=newVal;
                            printf("MRP Updated!\n");
                            break;
                        }
                    }
                    if(found==0)
                    {
                        printf("ID Not Found\n");
                    }
                    break;

                case 4:
                    printf("Enter Product ID: ");
                    scanf("%d",&purchase);
                    found=0;
                    for(j=0;j<10;j++)
                    {
                        if(item[j].ID==purchase)
                        {
                            found=1;
                            printf("Current Offer: %d\n",item[j].offer);
                            printf("Enter New Offer: ");
                            scanf("%d",&newVal);
                            item[j].offer=newVal;
                            printf("Offer Updated!\n");
                            break;
                        }
                    }
                    if(found==0)
                    {
                        printf("ID Not Found\n");
                    }
                    break;

                case 5:
                    printf("Enter Product ID: ");
                    scanf("%d",&purchase);
                    found=0;
                    for(j=0;j<10;j++)
                    {
                        if(item[j].ID==purchase)
                        {
                            found=1;
                            printf("Current Name: %s\n",item[j].name);
                            printf("Enter New Name: ");
                            scanf("%s",item[j].name);
                            printf("Name Updated!\n");
                            break;
                        }
                    }
                    if(found==0)
                    {
                        printf("ID Not Found\n");
                    }
                    break;

                case 6:
                    printf("Exiting Owner Panel\n");
                    break;

                default:
                    printf("Invalid Choice\n");
            }

        }while(choice!=6);
    }
    else if(role==2)
    {
        printf("\nWelcome Customer!\n");

        do
        {
            printf("\n---------Trend Invoice---------\n");
            printf("1. View Inventory Stock\n");
            printf("2. Purchase Items\n");
            printf("3. View Cart\n");
            printf("4. Checkout & Exit\n");
            printf("Enter your choice: ");
            scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                    printf("\nID\tOffer\tMRP\tStock\tName\n");
                    for(i=0;i<10;i++)
                    {
                        printf("%d\t%d\t%d\t%d\t%s\n",
                               item[i].ID,
                               item[i].offer,
                               item[i].MRP,
                               item[i].stock,
                               item[i].name);
                    }
                    break;

                case 2:
                    printf("Purchase Item With ID: ");
                    scanf("%d",&purchase);
                    found=0;
                    for(j=0;j<10;j++)
                    {
                        if(purchase==item[j].ID)
                        {
                            found=1;
                            printf("Item Available\n");
                            printf("Enter quantity to purchase: ");
                            scanf("%d",&quantity);

                            if(quantity<=item[j].stock)
                            {
                                item[j].stock=item[j].stock-quantity;
                                total=item[j].MRP*quantity;
                                k=item[j].ID;

                                cartID[cartCount]=item[j].ID;
                                cartQty[cartCount]=quantity;
                                cartTotal[cartCount]=total;
                                grandTotal=grandTotal+total;
                                cartCount=cartCount+1;

                                printf("Item Added To Cart Successfully\n");
                            }
                            else
                            {
                                printf("Insufficient Stock\n");
                            }
                            break;
                        }
                    }
                    if(found==0)
                    {
                        printf("Item Not Found\n");
                    }
                    break;

                case 3:
                    if(cartCount==0)
                    {
                        printf("Cart Is Empty\n");
                    }
                    else
                    {
                        printf("\n------ Your Cart ------\n");
                        printf("ID\tQty\tTotal\n");
                        for(i=0;i<cartCount;i++)
                        {
                            printf("%d\t%d\t%d\n",cartID[i],cartQty[i],cartTotal[i]);
                        }
                        printf("Grand Total : %d\n",grandTotal);
                    }
                    break;

                case 4:
                    printf("\n------ Invoice ------\n");
                    printf("Purchased Item ID : %d\n",k);
                    printf("Purchased Quantity : %d\n",quantity);
                    printf("Total MRP : %d\n",total);
                    printf("Grand Total : %d\n",grandTotal);
                    printf("Thank You For Purchase!\n");
                    break;

                default:
                    printf("Invalid Choice\n");
            }

        }while(choice!=4);
    }
    else
    {
        printf("Invalid Role\n");
    }

    return 0;
}