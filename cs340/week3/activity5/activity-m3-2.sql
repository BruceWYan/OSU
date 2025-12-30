/* 
 * Citation: Is for the query
 * Date: 02/01/2024
 * Copied from: Canvas Week 3 Activity 5
 * Source: https://canvas.oregonstate.edu/courses/1946034/pages/activity-5-sql-queries-of-multiple-tables-joins?module_item_id=23809309
 */
SELECT InvoiceDetails.InvoiceID, Products.ProductName, InvoiceDetails.UnitPrice
FROM InvoiceDetails
INNER JOIN Products ON InvoiceDetails.ProductNumber = Products.ProductNumber
WHERE InvoiceDetails.InvoiceID = 3
ORDER BY InvoiceDetails.UnitPrice ASC;