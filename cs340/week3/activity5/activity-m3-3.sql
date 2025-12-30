/* 
 * Citation: Is for the query
 * Date: 02/01/2024
 * Copied from: Canvas Week 3 Activity 5
 * Source: https://canvas.oregonstate.edu/courses/1946034/pages/activity-5-sql-queries-of-multiple-tables-joins?module_item_id=23809309
 */
SELECT Customers.CustomerName, Invoices.InvoiceID, SUM(InvoiceDetails.LineTotal) AS LineSum
FROM InvoiceDetails
INNER JOIN Invoices ON InvoiceDetails.InvoiceID = Invoices.InvoiceID
INNER JOIN Customers ON Invoices.CustomerID = Customers.CustomerID
GROUP BY Invoices.InvoiceID
ORDER BY LineSum DESC;