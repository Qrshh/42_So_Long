Le fichier mlx42.supp est un script permettant d'enlever les leaks provoques par la MLX42.
Pour pouvoir utiliser ce fichier, utiliser la commande :
**valgrind --leak-check=full --keep-debuginfo=yes --suppressions=mlx42.supp ./so_long "maps/maps.ber"**

A l'heure actuelle il me reste le backtracking a gerer, ce qui sous-entend les leaks
