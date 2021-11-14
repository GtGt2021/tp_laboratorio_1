#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_validador.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int flagBin=-1;
    int flagTxt=-1;
    //int flagSaveBin=-1;
    //int flagSaveTxt=-1;
    int retornoAdd;
    char letra[2];
    int salir;
    int ErrorRetorno;

    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("BIENVENIDOS AL LINKEDLIST DE GUSTAVO VARGAS");
    do{
        printf(
        		"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)"
        		"\n3. Alta de empleado \n4. Modificar datos de empleado \n5. Baja de empleado \n6. Listar empleados \n7. Ordenar empleados "
    			"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
        		"\n10. Salir\n" );
    	utn_pedirIntAUsuarioConLimites(&option, 1, 10, 3, "Ingrese Opcion Deseada", "Error");
        switch(option)
        {
            case 1:
            	if(flagTxt==-1 && flagBin==-1)
            	{
            		ErrorRetorno=controller_loadFromText("data.csv",listaEmpleados);
            		if(ErrorRetorno==0)
            		{
            			printf("lista Leida\n");
            		}
            		else
            		{
            			if(ErrorRetorno==-1)
            			{
            				if(utn_PedirCualquierCaracterAUsuario(letra, 2, 0, "Presione S si desea Crear el Archivo o cualquier otra tecla para continuar", "Volviendo Al Inicio")==0 )
							{
								if(letra[0]=='s' || letra[0]=='S')
								{
									FILE* f2=fopen("data.csv", "w");
									if(f2!=NULL)
									{
										fclose(f2);
										printf("Archivo Texto Creado\n");
									}
								}

							}
            			}

            		}

            	}
               	else
            	{
            		printf("ya cargaste previamente un archivo");
            	}
            	flagTxt=0;
                break;
            case 2:
            	if (flagTxt==-1 && flagBin==-1)
            	{
            		printf("Sin Tiempo Para Crearla :(");
            		flagBin=0;
            	}
            	else
            	{
            		printf("ya cargaste previamente un archivo");
            	}
            	break;
            case 3:
            	if(flagBin==0 || flagTxt==0)
            	{
            		retornoAdd=controller_addEmployee(listaEmpleados);
                	if(retornoAdd==0)
                	{
                	printf("Empleado Agregado Con Exito\n");
                	}
                	else
                 	{
                		if(retornoAdd==-1)
                		{
                			printf("Te quedastes sin Memoria\n");
                		}
                		else
                		{
                			printf("Error al Ingresar Datos para Cargar Empleado\n");
                		}
            		}
            	}
            	else
            	{
            		printf("Primero Intenta Cargar los Archivos de Datos bien sea binario o texto\n");
            	}
            	break;
            case 4:
            	if(ll_len(listaEmpleados)>0)
            	{
            		controller_ListEmployee(listaEmpleados);
            		if(controller_editEmployee(listaEmpleados)==0)
            		{
            			printf("editado con exito\n");
            		}

            	}
            	else
            	{
            		printf("no hay empleados para modificar\n");
            	}
                        	break;
            case 5:
            	if(ll_len(listaEmpleados)>0)
            	{
            		controller_ListEmployee(listaEmpleados);
            		if(controller_removeEmployee(listaEmpleados)==0)
            		{
            			printf("borrado con exito\n");
            		}

            	}
            	else
            	{
            		printf("no hay empleados para eliminar\n");
            	}
                        	break;
            	break;
            case 6:
            	if(ll_len(listaEmpleados)>0)
            	{
            		controller_ListEmployee(listaEmpleados);
            	}
            	else
            	{
            		printf("lista vacia\n");
            	}

            	break;
            case 7:
            	if(ll_len(listaEmpleados)>0)
            	{
            		if(controller_sortEmployee(listaEmpleados)==0)
            		{
            			printf("Lista Ordenada Correctamente\n");
            			controller_ListEmployee(listaEmpleados);
            		}
            		else
            		{
            			printf("error de Lista");
            		}
               	}
            	else
            	{
            		printf("lista vacia\n");
            	}

            	break;
            case 8:
            	if(flagTxt==-1)
            	{
            		printf("Se Sobreescribira el Archivo en caso de Existir\n");
            		if(utn_PedirCualquierCaracterAUsuario(letra, 2, 0, "Presione S si desea Guardar de Todas Maneras", "Volviendo Al Inicio")==0 )
            		{
						if(letra[0]=='s' || letra[0]=='S')
						{
							if(controller_saveAsText("data.csv", listaEmpleados)==0)
							{
								printf("Guardado Con exito");
							}
							else
							{
								printf("Error al intentar escribir en el disco");
							}
						}

            		}
            	}
            	else
            	{
            		if(controller_saveAsText("data.csv", listaEmpleados)==0)
					{
						printf("Guardado Con exito");
					}
					else
					{
						printf("Error al intentar escribir en el disco");
					}
            	}

            	break;
            case 9:
            	printf("Sin Tiempo Para Crearla :(");
            	break;
            case 10:
            	if(utn_pedirIntAUsuarioConLimites(&salir, 1, 3, 3, "Desea Guardar los Cambios Antes de Salir:\n1.-Para Guardar en Txt\n2.-Para Guardar en Binario\n3.-Para Salir sin Guardar", "Error de Seleccion")==0)
            	{
            		switch(salir)
            		{
            		case 1:
                    	if(controller_saveAsText("data.csv", listaEmpleados)==0)
        				{
                    		printf("Guardado Con exito");
        				}
                    	else
                    	{
                    		printf("Error al intentar escribir en el disco");
                    	}
            			break;
            		case 2:
            			//controller_saveAsBinary("dataBin", listaEmpleados);
            			break;
            		case 3:
            			break;
            		}
            	}
            	else
            	{
            		option=0;
            	}
            	break;
        }
    }while(option != 10);
    return 0;
}

