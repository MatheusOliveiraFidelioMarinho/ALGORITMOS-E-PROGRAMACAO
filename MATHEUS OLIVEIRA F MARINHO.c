#include <stdio.h>

int main() {
		int idade=0;
		
		printf("Informe a sua idade:");
		scanf("%d", & idade);
		
		if(idade<0){
			printf("Ainda nao nasceu");
		}
			else{
				if(idade<16){
					printf("Nao vota");
				}
					else{
						if(idade<18){
							printf("Voto opcional");
						}
							else{
								if(idade<65){
									if(idade==41){
										printf("Nao vota e ganha um premio");
									}else{
										printf("Voto obrigatorio");
									}
									
									
								}
									else{
										if(idade>=65){
											if(idade==88){
												printf("Nao vota e ganha um premio");
											}else{
												printf("Voto opcional");
											}
											
										}
										
									}
							}
					}
			}
						}			