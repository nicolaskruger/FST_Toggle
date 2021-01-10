# :joystick: FST_Toggle

## :pushpin: Tabela com os Conteúdos
 * [Description](#book-Descrição)
 * [Technology](#hammer_and_wrench-Technology)
 * [Task](#scroll-Task)
 * [Install](#gear-Install)
 * [Como fazer](#scroll-Task)
 * [Requisitos](#bookmark_tabs-Requisitos)
 ## :book: Descrição 
 Esse é um repositório, com o intuito de revisar alguns conceitos para me preparar para o estágio na Unisinos 
## :hammer_and_wrench: Technology
 * [STM32](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)
 * [C](https://pt.wikipedia.org/wiki/C_(linguagem_de_programa%C3%A7%C3%A3o))
 * [board STM32L053R8](https://www.st.com/en/evaluation-tools/nucleo-l053r8.html)
## :scroll: Task
- [ ] configurar o RTC 
- [ ] programar algum push-button para fazer um toggle do LED de usuário (Se tu tiver LED para conectar, pode ser via GPIO)
- [ ] configurar um GPIO para desligar o LED caso o LED esteja ativo
- [ ] imprime na serial o RTC
## :hammer_and_wrench: Como fazer
- [ ] criar uma maquina de estados no "main.c" 
- [ ] O passo (1) tu cria um arquivo .c e .h para implementar a biblioteca para o RTC, sugestão nome: rtc_lib.[ch]
- [ ] O passo (2) tu cria um arquivo .c e .h para implementar a biblioteca para o push-buttom, sugestão nome: pb_lib.[ch]
- [ ] O passo (3) pode fazer direto na máquina de estados, é bem simples esse.
## :bookmark_tabs: Requisitos
* [board STM32L053R8](https://www.st.com/en/evaluation-tools/nucleo-l053r8.html)
* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)

