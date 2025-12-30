/* 
 * Citation: Is for the query
 * Date: 02/01/2024
 * Copied from: Canvas Week 3 Activity 6
 * Source: https://canvas.oregonstate.edu/courses/1946034/pages/activity-6-retrieving-invoice-slip-data?module_item_id=23809310
 */
SELECT Products.ProductNumber, Products.ProductName, InvoiceDetails.LineTotal, InvoiceDetails.OrderQty, InvoiceDetails.UnitPrice
FROM InvoiceDetails
INNER JOIN Products ON InvoiceDetails.ProductNumber = Products.ProductNumber
WHERE InvoiceDetails.InvoiceID = 3;