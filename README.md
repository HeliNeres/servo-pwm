# Controle de Servomotor com PWM

Atividade da aula síncrona do dia 06/02 - Tarefa 2.

## Vídeo de Apresentação

[https://youtube.com/shorts/8SXNiLzMIlk?feature=share](https://youtube.com/shorts/8SXNiLzMIlk?feature=share "https://youtube.com/shorts/8SXNiLzMIlk?feature=share")

## Instruções de uso

1. Conecte o **BitDogLab** ao computador usando o cabo micro-USB com o servomotor conectado ao GPIO22, ou utilize a simulação do Wokwi no arquivo diagram.json.
2. Compile o Programa e carregue para o microcontrolador.
3. Acesse o Monitor Serial para observar as saída.
4. O braço do servomotor irá variar de 0° e 180°, parando por 5 segundos em 0°, 90° e 180°.

## Testes

Os seguintes testes básicos foram implementados:

* Verificação do acionamento correto do servomotor.
* Saídas do ângulo esperado no monitor serial.

## Teste com LED

Se for conectado um LED à saída do PWM poderá se observar a variação da luminosidade do LED e as pausas nos valores determinados variando entre 2,5% e 12% da intensidade.
