//_________________RED
void red()
{
    printf("\033[0;31m");
}


//_________________GREEN
void green()
{
    printf("\033[0;32m");

}


//_________________YELLOW
void yellow()
{
    printf("\033[0;33m");
}


//_________________RESETcolor
void resetCOLOR()
{
    printf("\033[0m");
}

//_________________TIME
void getTIME(int i)
{
    time_t dt;
    struct tm* timeInfo;
    time(&dt);
    timeInfo=localtime(&dt);
    strcpy(logg[i].dateTIME,asctime(timeInfo));
    printf("%s\n", asctime(timeInfo));
}


//_________________adding multiple/single products
int quantiteTemp; //NeededAsglobalVar :)
void add(n) 
{   int i,isCANCEL=1;
    char cancel[10];
    //so the variable in he struct wont be edited

    
    for (i = 0; i < n; i++)
    {   
        sameCODE:  
        resetCOLOR();       
        printf("Entrer le nom du produit :\n");
        scanf("\n%[^\n]s ",product[tProducts].nom);
        if ( strlen(product[tProducts].nom)>20 )
        {   
            red();
            printf("Vous avez depassez la limite des characteres(20)!\n");
            resetCOLOR();
            goto sameCODE;
        }
        
        printf("Entrer le code du produit :\n");
        scanf("%s",product[tProducts].code);
        

        for ( int j = 0; j < tProducts; j++)
        {  
            //_______checking if the code already exists
            if(strcmp (product[tProducts].code,product[j].code)==0 )
            {   red();
                printf("Ce code de produit existe deja !\n\n");
                printf("Tapez n\'importe quelle touche pour reessayer ou 'annuler' pour annuler:\n");
                resetCOLOR();
                scanf("%s",cancel);
                
                if (strcmp(cancel,"annuler")==0)
                {   
                    isCANCEL=0;
                    break;
                }
                if (strcmp(cancel,"annuler")!=0)
                {   
                    goto sameCODE;
                    
                }
                
            }
        
        }
        if (isCANCEL==0)
        {   
            system("cls");
            break;
        }
        
        resetCOLOR();
        unvalidPRICE:
        printf("Entrer le prix HT du produit en DH:\n");
        
        if(scanf("%f",&product[tProducts].prixHT)!=1) 
        {
            red();
            printf("Valeur Invalid, Veuiller relancer le Programme.");
            resetCOLOR();
            sleep(1);
            exit(1);
        }
        
        if (product[tProducts].prixHT < 0)
        {   //_______checking if the input is correct

            printf("Vous avez entrer une valeur invalide, veuiller reessayer:\n");
            goto unvalidPRICE;
        }
        
        printf("Entrer la quantite du produit :\n");
        
        if(scanf("%d",&product[tProducts].quantite)!=1) 
        {
            red();
            printf("Valeur Invalid, Veuiller relancer le Programme.");
            resetCOLOR();
            sleep(1);
            exit(1);
        }
        product[tProducts].quantite+=quantiteTemp;
        system("cls");
        green();
        printf("Produit ajout avec succes.\n");
        tProducts++;
        printf("%d/1000 produits.\n",tProducts);
        
        yellow();
        system("pause");
        resetCOLOR();
        system("cls");
        
    } 
}


//_________________sorting products by name
void listAlph()
{   
    
    P productTemp;
    for (int i = 0; i < tProducts; i++)
    {
        for (int j = 0; j < tProducts-i-1; j++)
        {
            if (strcmp(product[j].nom,product[j+1].nom)<0)
            {
                productTemp=product[j+1];
                product[j+1]=product[j];
                product[j]=productTemp;
            }
            
        }
    }
    system("cls");
    for (int k = 0; k < tProducts; k++)
    {  
        green();
        printf("%s                ",product[k].nom);resetCOLOR();
        printf("'%s'                ",product[k].code);
        printf("%d (En Stock)                ",product[k].quantite);
        printf("%.2f DH TTC                \n\n",product[k].prixHT*1.15);

    }
    yellow();
    system("pause");
    resetCOLOR();
}


//_________________sorting products by price
void listPrice()
{
    P priceTemp;
    for (int i = 0; i < tProducts; i++)
    {
        for (int j = 0; j < tProducts-i-1; j++)
        {
            if (product[j].prixHT<product[j+1].prixHT)
            {
                priceTemp=product[j+1];
                product[j+1]=product[j];
                product[j]=priceTemp;
            }
            
        }
    }
        system("cls");
    for (int k = 0; k < tProducts; k++)
    {  
        green();
        printf("%.2f DH TTC                ",product[k].prixHT*1.15);resetCOLOR();
        printf("%s                ",product[k].nom);
        printf("'%s'                ",product[k].code);
        printf("%d (En Stock)                \n",product[k].quantite);
        
    }
    yellow();
    system("pause");
    resetCOLOR();

}


//_________________buy a product
void buy(){
    char codeCMP[20],confirm[20];
    int isFound, howMANY;
    system("cls");
    printf("Entrez le code du produit que vous voullez acheter :\n");
    purchaseFAILED:
    scanf("\n%[^\n]s",&codeCMP);
    int i;
    for (i = 0; i < tProducts; i++)
    {  
        isFound=1;
        if (strcmp(codeCMP,product[i].code)==0)
            {   yellow();
                printf("Resultat :\n\n\n");
                green();
                printf("%s                ",product[i].nom);
                printf("'%s'                ",product[i].code);
                printf("%d (En Stock)                ",product[i].quantite);
                printf("%.2f DH TTC                \n",product[i].prixHT*1.15);
                isFound=0;
                resetCOLOR();
                break;  
            }   
    }
    if(isFound)
    {
        red();
        printf("Le code saisie est introuvable veuiller reessayer :\n");
        resetCOLOR();
        goto purchaseFAILED;
    }
    printf("Entrer n\'importe quelle touche  pour confirmer l\'achat ou 0 pour annuler :\n");
    scanf("%s",&confirm);

    if(confirm!=0)
    {   noSTOCK:
        printf("Quelle est la quantite que vous voullez acheter :\n");
        
        if(scanf("%d",&howMANY)!=1) 
        {
            red();
            printf("Valeur Invalid, Veuiller relancer le Programme.");
            resetCOLOR();
            sleep(1);
            exit(1);
        }
        if (howMANY>product[i].quantite)
        {
            red();
            printf("Stock insuffisant!\n%d exemplaire(s) restant(s)\n",product[i].quantite);
            resetCOLOR();
            goto noSTOCK;
        }
        system("cls");
        product[i].quantite-=howMANY;
        yellow();
        getTIME(i);
        green();
        printf("La commande est bien reussie:\n\n");
        printf("%s                ",product[i].nom);
        printf("'%s'                ",product[i].code);
        printf("%d (En Stock)                ",product[i].quantite);
        printf("%.2f DH TTC                \n",product[i].prixHT*howMANY*1.15);
        resetCOLOR();
        strcpy(logg[i].code,product[i].code);
        strcpy(logg[i].nom,product[i].nom);
        logg[i].PrixUniteTtc=product[i].prixHT*1.15;
        logg[i].quantite=howMANY;
        yellow();
        system("pause");
        resetCOLOR();
    }
}


//_________________searchCODE
int isFOUND=1; float Scode; //NeededAsglobalVar :)
void searchCODE()
{ 
    system("cls");
    printf("Recherche par code:\n");
    scanf("%f",&Scode); 

    for (int i = 0; i < tProducts; i++)
    {
        if(Scode==product[i].prixHT)
        {   
            green();
            printf("%s                ",product[i].nom);resetCOLOR();
            printf("'%s'                ",product[i].code);
            printf("%d (En Stock)                ",product[i].quantite);
            printf("%.2f DH HT                \n",product[i].prixHT);
            resetCOLOR();
            isFOUND=0;
        }
    }
    if (isFOUND==1)
    { 
        red();
        printf("Aucun resultat!\n");
        resetCOLOR();
    }
    yellow();
    system("pause");
    resetCOLOR();
}

//_________________searchQUANTITE
void searchQUANTITE()
{   
  system("cls");  
  int Squantite;  
  printf("Enter la quantite:\n");
  
  if(scanf("%d",&Squantite)!=1) 
        {
            red();
            printf("Valeur Invalid, Veuiller relancer le Programme.");
            resetCOLOR();
            sleep(1);
            exit(1);
        }
  for (int i = 0; i < tProducts; i++)
  {
        if(Squantite<=product[i].quantite)
        {   green();
            printf("%s                ",product[i].nom);resetCOLOR();
            printf("'%s'                ",product[i].code);
            printf("%d (En Stock)                ",product[i].quantite);
            printf("%.2f DH HT                \n",product[i].prixHT);
            resetCOLOR();
        }
  }
  yellow();
  system("pause");
  resetCOLOR();
}


//_________________searchSTOCK
void searchSTOCK()
{  system("cls");
  for (int i = 0; i < tProducts; i++)
  {
        if(product[i].quantite<=3)
        {   
            
            printf("%s                ",product[i].nom);
            printf("'%s'                ",product[i].code);
            printf("%d (En Stock)                ",product[i].quantite);
            green();
            printf("%.2f DH HT                \n",product[i].prixHT);
            resetCOLOR();
        }
  }
  yellow();
  system("pause");
  resetCOLOR();
}


//_________________addSTOCK
void addSTOCK()
{   
    int addQUANTITE;
    yellow();
    printf("Ajouer au stock:\n\n");
    resetCOLOR();
    searchCODE();
    for (int i = 0; i < tProducts; i++)
    {
        if (isFOUND==0)
        {   unvalid:
            printf("Entrer la quantite a ajoutee :\n");
            
            if(scanf("%d",&addQUANTITE)!=1) 
            {
                red();
                printf("Valeur Invalid, Veuiller relancer le Programme.");
                resetCOLOR();
                sleep(1);
                exit(1);
            }
            if (addQUANTITE<=0)
            {   
                red();
                printf("Entrez une valeur valide!\n");
                resetCOLOR();
                goto unvalid;
            }
            product[i].quantite+=addQUANTITE;
            system("cls");
            green();
            printf("Nouvelle quantite:%d\n",product[i].quantite);
            resetCOLOR();
            break;
            
        }   
    }
    yellow();
    system("pause");
    resetCOLOR();
}


//_________________DELETE
void DELETE()
{   
    char confirm[10];
    searchCODE();
    if (isFOUND==0)
    {
        printf("Taper 1 pour supprimer ce produit ou d\'import autre touche pour annuler :\n");
        scanf("%s",&confirm);
        if(strcmp(confirm,"1")==0)
        {
            for (int i = 0; i < tProducts; i++)
            {
                if (strcmp(Scode,product[i].code)==0)
                {   
                    for (int j = i; j < tProducts-i; j++)
                    {
                        product[j]=product[j+1];
                    }
                    tProducts--;
                    break;
                } 
            }
        }
        
    } 
    
}


//_________________TOTALtoday
float totalTODAY;
void TotalSoldToday()
{   
    
    for (int i = 0; i < tProducts; i++)
    {
        totalTODAY+=logg[i].PrixUniteTtc*logg[i].quantite;
        numberSOLD++;
    }
    
    system("cls");
    printf("Le total des ventes pour le moment est:");
    green();
    printf("%.2f DH\n",totalTODAY);
    
    yellow();
    system("pause");
    resetCOLOR();
}


//_________________MAXtoday
void maxTODAY()
{   float max=logg[0].PrixUniteTtc;
    for (int i = 0; i < tProducts; i++)
    {   
       if (logg[i].PrixUniteTtc>logg[i+1].PrixUniteTtc)
       {
            max=logg[i].PrixUniteTtc;
       }
    }
    system("cls");
    printf("le Max des prix des produits vendus en journee courante: ");
    green();
    printf("%.2f DH\n",max);
    
    yellow();
    system("pause");
    resetCOLOR();
    
}


//_________________MINtoday
void minTODAY()
{   float min=logg[0].PrixUniteTtc;
    for (int i = 0; i < tProducts; i++)
    {      
       if (logg[i].PrixUniteTtc<logg[i+1].PrixUniteTtc)
       {
            min=logg[i].PrixUniteTtc;
       }
    }
    system("cls");
    printf("le Min des prix des produits vendus en journee courante: ");
    red();
    printf("%.2f DH\n",min);
    yellow();
    system("pause");
    resetCOLOR();
    
}


//____________________________________MENU
void MENU()
{   
    int menu,n,sortBY,searchTYPE,wichSTATS;
    system("cls");
    printf("1-  Ajouter un nouveau produit.\n");usleep(200000);
    printf("2-  Ajouter plusieurs nouveaux produits.\n");usleep(200000);
    printf("3-  Lister tous les produits.\n");usleep(200000);
    printf("4-  Acheter produit.\n");usleep(200000);
    printf("5-  Rechercher les produits.\n");usleep(200000);
    printf("6-  Etat du stock.\n");usleep(200000);
    printf("7-  Alimenter le stock.\n");usleep(200000);
    printf("8-  Supprimer les produits.\n");usleep(200000);
    printf("9-  Statistique de vente.\n");usleep(200000);  
    
    yellow();
    WrongMenuChoice:
    printf("Entrer le nombre qui convient l\'operation souhaitee :\n");
    resetCOLOR();
    scanf("%d",&menu);
    if (menu<0 && menu>10)
    {
        goto WrongMenuChoice;
    }
    
    switch (menu)
    {
        case 1:
            system("cls");
            add(1);
            break;

        case 2:
            system("cls");
            yellow();
            printf("Combien de produit voulez-vous ajoute :\n");
            resetCOLOR();
            scanf("%d",&n);
            add(n);
            break;

        case 3:   
            system("cls");
            printf("1- Par ordre alphabetique croissant.\n");
            usleep(200000);
            printf("2- Par ordre decroissant du prix.\n");
            yellow();
            printf("Entrer le nombre qui convient l'operation souhaitee :\n");
            resetCOLOR();
            wrongCHOICE:
            scanf("%d",&sortBY);
            system("cls");
            switch (sortBY)
            {
                case 1:
                    listAlph();
                    break;

                case 2:
                    listPrice();
                    break;    
                
                default:
                    red();
                    printf("Valeur Invalid, Veuiller relancer le Programme.");
                    resetCOLOR();
                    sleep(1);
                    exit(1);
                    break;  
            }                                               //__________________________SOUS______MENU
            break;

        case 4:
            buy();
            break;

        case 5:
            system("cls");
            printf("1- Recherche par code.\n");
            printf("2- Recherche par quantite.\n");
            printf("Entrer le nombre qui convient l'operation souhaitee :\n");
            scanf("%d",&searchTYPE);
            switch (searchTYPE)
            {
                case 1:
                    searchCODE();
                    break;

                case 2:
                    searchQUANTITE();
                    break;
                    
                default:
                    red();
                    printf("Valeur Invalid, Veuiller relancer le Programme.");
                    resetCOLOR();
                    sleep(1);
                    exit(1);
                    break;
            }                                             //__________________________SOUS______MENU
            break;

        case 6: 
            system("cls");
            searchSTOCK();
            break;

        case 7: 
            system("cls");
            addSTOCK();
            break;

        case 8: 
            system("cls");
            DELETE();
            break;

        case 9:
            system("cls");
            printf("1- Total des prix des produits vendus dans la journee courante.\n");
            printf("2- Total la moyenne des prix des produits vendus dans la journee courante.\n");
            printf("3- Total le max des prix des produits vendus dans la journee courante.\n");
            printf("4- Total le min des prix des produits vendus dans la journee courante.\n\n");
            yellow();
            printf("Afficher:\n");
            resetCOLOR();
            scanf("%d",&wichSTATS);
            system("cls");
            switch (wichSTATS)
            {
                case 1:
                    TotalSoldToday();
                    break;

                case 2:
                    TotalSoldToday();
                    usleep(200000);
                    system("cls");
                    green();
                    printf("La moyenne des prix des produits vendus dans la journee courante :");
                    printf("%.2f\n",totalTODAY/numberSOLD);
                    resetCOLOR();                
                    break;

                case 3:
                    maxTODAY();
                    break;

                case 4:
                    minTODAY();
                    break;    
                
                default:
                    red();
                    printf("Valeur Invalid, Veuiller relancer le Programme.");
                    resetCOLOR();
                    sleep(1);
                    exit(1);
                    break;
            }
            break;                            
       
        default:
                    red();
                    printf("Valeur Invalid, Veuiller relancer le Programme.");
                    resetCOLOR();
                    sleep(1);
                    exit(1);
                break;
    }
    
}






            /////////////////////////                    THE END  :)                
