-- phpMyAdmin SQL Dump
-- version 5.2.1-1.el7.remi
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Feb 08, 2024 at 10:26 PM
-- Server version: 10.6.16-MariaDB-log
-- PHP Version: 8.2.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cs340_yanbr`
--

-- --------------------------------------------------------

--
-- Table structure for table `CuisineTypes`
--

CREATE TABLE `CuisineTypes` (
  `cuisineTypeID` int(11) NOT NULL,
  `type` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Locations`
--

CREATE TABLE `Locations` (
  `locationID` int(11) NOT NULL,
  `city` varchar(50) NOT NULL,
  `state` varchar(50) NOT NULL,
  `country` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `RestaurantChains`
--

CREATE TABLE `RestaurantChains` (
  `restaurantChainID` int(11) NOT NULL,
  `name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `RestaurantCuisines`
--

CREATE TABLE `RestaurantCuisines` (
  `restaurantID` int(11) NOT NULL,
  `cuisineTypeID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `RestaurantLocations`
--

CREATE TABLE `RestaurantLocations` (
  `restaurantID` int(11) NOT NULL,
  `locationID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Restaurants`
--

CREATE TABLE `Restaurants` (
  `restaurantID` int(11) NOT NULL,
  `restaurantName` varchar(50) NOT NULL,
  `description` varchar(255) NOT NULL,
  `restaurantChainID` int(11) NOT NULL,
  `avgRating` decimal(18,1) NOT NULL,
  `avgPrice` varchar(50) NOT NULL,
  `popularOrder` varchar(50) NOT NULL,
  `photo` blob NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Reviews`
--

CREATE TABLE `Reviews` (
  `reviewID` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `restaurantID` int(11) NOT NULL,
  `review` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE `Users` (
  `userID` int(11) NOT NULL,
  `username` varchar(50) NOT NULL,
  `email` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL,
  `fname` varchar(50) NOT NULL,
  `lname` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Visited`
--

CREATE TABLE `Visited` (
  `userID` int(11) NOT NULL,
  `restaurantID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `CuisineTypes`
--
ALTER TABLE `CuisineTypes`
  ADD PRIMARY KEY (`cuisineTypeID`);

--
-- Indexes for table `Locations`
--
ALTER TABLE `Locations`
  ADD PRIMARY KEY (`locationID`);

--
-- Indexes for table `RestaurantChains`
--
ALTER TABLE `RestaurantChains`
  ADD PRIMARY KEY (`restaurantChainID`);

--
-- Indexes for table `RestaurantCuisines`
--
ALTER TABLE `RestaurantCuisines`
  ADD KEY `restaurantID` (`restaurantID`),
  ADD KEY `cuisineTypeID` (`cuisineTypeID`);

--
-- Indexes for table `RestaurantLocations`
--
ALTER TABLE `RestaurantLocations`
  ADD KEY `restaurantID` (`restaurantID`),
  ADD KEY `locationID` (`locationID`);

--
-- Indexes for table `Restaurants`
--
ALTER TABLE `Restaurants`
  ADD PRIMARY KEY (`restaurantID`),
  ADD KEY `restaurantChainID` (`restaurantChainID`);

--
-- Indexes for table `Reviews`
--
ALTER TABLE `Reviews`
  ADD PRIMARY KEY (`reviewID`),
  ADD KEY `userID` (`userID`),
  ADD KEY `restaurantID` (`restaurantID`);

--
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`userID`);

--
-- Indexes for table `Visited`
--
ALTER TABLE `Visited`
  ADD KEY `restaurantID` (`restaurantID`),
  ADD KEY `userID` (`userID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `CuisineTypes`
--
ALTER TABLE `CuisineTypes`
  MODIFY `cuisineTypeID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Locations`
--
ALTER TABLE `Locations`
  MODIFY `locationID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `RestaurantChains`
--
ALTER TABLE `RestaurantChains`
  MODIFY `restaurantChainID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Restaurants`
--
ALTER TABLE `Restaurants`
  MODIFY `restaurantID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Reviews`
--
ALTER TABLE `Reviews`
  MODIFY `reviewID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Users`
--
ALTER TABLE `Users`
  MODIFY `userID` int(11) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `RestaurantCuisines`
--
ALTER TABLE `RestaurantCuisines`
  ADD CONSTRAINT `RestaurantCuisines_ibfk_1` FOREIGN KEY (`cuisineTypeID`) REFERENCES `CuisineTypes` (`cuisineTypeID`),
  ADD CONSTRAINT `RestaurantCuisines_ibfk_2` FOREIGN KEY (`restaurantID`) REFERENCES `Restaurants` (`restaurantID`);

--
-- Constraints for table `RestaurantLocations`
--
ALTER TABLE `RestaurantLocations`
  ADD CONSTRAINT `RestaurantLocations_ibfk_1` FOREIGN KEY (`locationID`) REFERENCES `Locations` (`locationID`),
  ADD CONSTRAINT `RestaurantLocations_ibfk_2` FOREIGN KEY (`restaurantID`) REFERENCES `Restaurants` (`restaurantID`);

--
-- Constraints for table `Restaurants`
--
ALTER TABLE `Restaurants`
  ADD CONSTRAINT `Restaurants_ibfk_2` FOREIGN KEY (`restaurantChainID`) REFERENCES `RestaurantChains` (`restaurantChainID`);

--
-- Constraints for table `Reviews`
--
ALTER TABLE `Reviews`
  ADD CONSTRAINT `Reviews_ibfk_1` FOREIGN KEY (`restaurantID`) REFERENCES `Restaurants` (`restaurantID`),
  ADD CONSTRAINT `Reviews_ibfk_2` FOREIGN KEY (`userID`) REFERENCES `Users` (`userID`);

--
-- Constraints for table `Visited`
--
ALTER TABLE `Visited`
  ADD CONSTRAINT `Visited_ibfk_1` FOREIGN KEY (`restaurantID`) REFERENCES `Restaurants` (`restaurantID`),
  ADD CONSTRAINT `Visited_ibfk_2` FOREIGN KEY (`userID`) REFERENCES `Users` (`userID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
