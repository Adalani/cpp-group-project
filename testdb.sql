-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 03, 2018 at 11:29 PM
-- Server version: 10.1.36-MariaDB
-- PHP Version: 7.2.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `testdb`
--

-- --------------------------------------------------------

--
-- Table structure for table `kitchen`
--

CREATE TABLE `kitchen` (
  `itemID` int(8) NOT NULL,
  `itemName` tinytext COLLATE utf8mb4_unicode_ci,
  `itemPrice` decimal(14,2) DEFAULT NULL,
  `itemInv` tinyint(12) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `kitchen`
--

INSERT INTO `kitchen` (`itemID`, `itemName`, `itemPrice`, `itemInv`) VALUES
(1, 'sink', '125.99', 1),
(2, 'chair', '29.99', 1),
(3, 'chair', '29.99', 1),
(4, 'chair', '29.99', 1),
(6, 'jhg', '50.25', 1),
(7, 'jsdgfds', '548.25', 3),
(8, 'dishes', '52.62', 4),
(9, 'sfneds', '58.25', 100),
(10, 'fridge', '985.98', 50),
(11, 'pots', '25.99', 58),
(12, 'spatula', '5.96', 127),
(13, 'dishwasher', '599.99', 5),
(14, 'forks', '5.99', 127),
(15, 'phospor-washers', '58.33', 127),
(16, 'big-chairs', '58.36', 58),
(17, 'drawers', '45.65', 65);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `kitchen`
--
ALTER TABLE `kitchen`
  ADD PRIMARY KEY (`itemID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `kitchen`
--
ALTER TABLE `kitchen`
  MODIFY `itemID` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
