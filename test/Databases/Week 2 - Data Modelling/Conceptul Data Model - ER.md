Examples of this:
![[Screenshot 2022-10-05 at 13.31.39.png ]]
![[Screenshot 2022-10-05 at 13.32.13.png | 300x300]]

Cusomter -> Order:
 - Min = 0 because the customer can have 0 orders
 - Max = many because they can have as many orders as they like
Order -> Customer:
- Min = 1 because you need at least one customer for each order
- Max = 1 because each order is only linked to a single customer


Order -> Product:
- Min = 1 because they need to add a product in order to be included
- Max = many as they can order as many as they want
Product -> Order:
- Min = 0 as they might not order the product. All products doesn't exist on the basis if a customer sends an orderl
- Max = many


