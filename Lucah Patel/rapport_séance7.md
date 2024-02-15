Avancement :
  - Le tank est maintenant contrôlable à distance avec le téléphone.
  - Les fils sont bien organisés.
  - Le composant hc-06 marche maintenant
  - Les servomoteurs marchent.


Tache Effectuer :
  - BT Contrôleur est maintenant fini :
    
    ![Screenshot_20240215_195638_Bluetooth Electronics](https://github.com/bogwee/ProjetArduino/assets/134391638/d83bc71b-fba8-4653-848a-34ffa830be2b)
    
      - 4 boutons de direction avancée vers la gauche, vers la droite, reculer vers la gauche, vers la droite, reculer tout droit
      - 1 slider pour la vitesse de déplacement, pwm
      - 2 slider pour les servomoteurs rotation sur l'axe x et z
      - Un bouton rouge pour l'arrêt complet
      - Et 2 boutons bleu et jaune pour tirer et arrêter de tirer les projectiles

  - Les fils sont bien rangés.
  - Le breadboard et les piles sont fixer
  - Attachement des moteurs sur le tube, la distance calculée permet une propulsion maximale du projectile avec une vitesse de projection de v0 = 6m.s ayant une distance maximale de projection d = 2m
  - Code complet avec servomoteur et moteur du tube


Problem Renconter :
  - PWM : vu qu'il n'y a que 2 pwm sur la carte arduino qui sont séparer sur les 8 pattes existantes, ainsi que le servomoteur ont besoin d'un pwm quand on utilise servo.write(...)
    les servomoteurs vont donc capturer le pwm d'une des pattes qui dans notre cas est utiliser pour les moteurs 12 V, il y a donc une interférence de la fréquence émise sur le servomoteur
    donc quand les moteurs 12 V bouge le servomoteur va aussi bouger de la même manière.
    
  - Un des moteurs ne marche pas dans un sens, ce n'est pas un problème de pont H, ce n'est pas un problème de voltage, toutes les tensions ont été vérifiées,
    cela est peut-être dû au fait comme citer ci-dessus au pwm dans la carte arduino.
