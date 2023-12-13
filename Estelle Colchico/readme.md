Compte rendu séance 1:

Nous avons commencer par faire des recherches sur...

Lorsque nous avons eu le squelette du chassis, j'ai commencé a regarder comment il fonctionnait. Deux moteurs et un pont en H L298N nous ont été fournis. J'ai donc fait des recherches sur leur fonctionnement puis j'ai commencé le branchement:
J'ai tout d'abord commencer par apprendre a souder, puis souder les fils reliant les moteurs et le pont en H tout en faisant attention a leur longeur. J'ai ensuite commencé le branchement du pont en H, j'ai rajouté deux jumpers pour connecter directement les broches enable (ENA et ENB) au 5V. J'ai ensuite connecté les sorties IN1, IN2, IN3 et IN4 sur des sorties PWM de la carte arduino, sans oublier le GND. par ailleur pour alimenter les moteurs nous avons eu besoin de 12V or la carte arduino ne fournit que 5V, nous avons donc chercher comment fournir ces 12V au pont H et nous avons branché comme le schéma ci dessous:
![image](https://github.com/bogwee/ProjetArduino/assets/130240101/880e2bbb-1bdb-4f8f-b88d-c99080405198)


![image](https://github.com/bogwee/ProjetArduino/assets/130240101/08027154-492f-4076-8632-77e8f51cadca)



