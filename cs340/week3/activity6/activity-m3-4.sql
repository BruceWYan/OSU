/* 
 * Citation: Is for the query
 * Date: 02/01/2024
 * Copied from: Canvas Week 3 Activity 6
 * Source: https://canvas.oregonstate.edu/courses/1946034/pages/activity-6-retrieving-invoice-slip-data?module_item_id=23809310
 */
SELECT Invoices.InvoiceID, Customers.CustomerName, Customers.City, Customers.State, CURDATE() AS Date, Invoices.TotalDue
FROM Customers
INNER JOIN Invoices ON Customers.CustomerID = Invoices.CustomerID
WHERE Invoices.InvoiceID = 3;