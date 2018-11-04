-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 04, 2018 at 10:11 PM
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
-- Table structure for table `bathroom`
--

CREATE TABLE `bathroom` (
  `itemID` int(8) NOT NULL,
  `itemName` varchar(32) COLLATE utf8mb4_unicode_ci NOT NULL,
  `itemPrice` decimal(14,2) NOT NULL,
  `itemInv` int(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `bathroom`
--

INSERT INTO `bathroom` (`itemID`, `itemName`, `itemPrice`, `itemInv`) VALUES
(5, 'sink', '220.00', 8),
(6, 'faucet', '100.00', 12),
(7, 'shower-head', '39.99', 14),
(8, 'mirror', '25.99', 11),
(9, 'towels', '10.99', 3),
(10, 'bath-mats', '15.00', 6);

-- --------------------------------------------------------

--
-- Table structure for table `bedroom`
--

CREATE TABLE `bedroom` (
  `itemID` int(8) NOT NULL,
  `itemName` varchar(32) COLLATE utf8mb4_unicode_ci NOT NULL,
  `itemPrice` decimal(14,2) NOT NULL,
  `itemInv` int(12) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `bedroom`
--

INSERT INTO `bedroom` (`itemID`, `itemName`, `itemPrice`, `itemInv`) VALUES
(5, 'bed-frames', '165.99', 10),
(6, 'matresses', '320.00', 4),
(7, 'night-stand', '65.00', 9),
(8, 'drawer-chest', '100.00', 7),
(9, 'duvets', '120.00', 12),
(10, 'pillow', '10.00', 1);

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
(17, 'drawers', '45.65', 65),
(18, 'pepper-mill', '9.45', 55),
(19, 'table', '420.00', 127);

-- --------------------------------------------------------

--
-- Table structure for table `livingroom`
--

CREATE TABLE `livingroom` (
  `itemID` int(11) NOT NULL,
  `itemName` varchar(32) COLLATE utf8mb4_unicode_ci NOT NULL,
  `itemPrice` decimal(14,2) NOT NULL,
  `itemInv` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `livingroom`
--

INSERT INTO `livingroom` (`itemID`, `itemName`, `itemPrice`, `itemInv`) VALUES
(3, 'sofa', '650.00', 5),
(4, 'coffee-table', '200.00', 15),
(5, 'wall-unit', '200.00', 10),
(6, 'media-furniture', '260.55', 16),
(7, 'rugs', '200.00', 2),
(8, 'light-fixtures', '150.00', 15);

-- --------------------------------------------------------

--
-- Table structure for table `office`
--

CREATE TABLE `office` (
  `itemID` int(8) NOT NULL,
  `itemName` varchar(32) COLLATE utf8mb4_unicode_ci NOT NULL,
  `itemPrice` decimal(14,2) NOT NULL,
  `itemInv` int(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `office`
--

INSERT INTO `office` (`itemID`, `itemName`, `itemPrice`, `itemInv`) VALUES
(1, 'desk', '250.00', 11),
(2, 'office chair', '122.59', 7),
(3, 'storage units', '255.99', 3),
(4, 'accessories', '10.00', 10),
(5, 'power cables', '42.99', 14),
(6, 'lamp', '25.99', 9);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bathroom`
--
ALTER TABLE `bathroom`
  ADD PRIMARY KEY (`itemID`);

--
-- Indexes for table `bedroom`
--
ALTER TABLE `bedroom`
  ADD PRIMARY KEY (`itemID`);

--
-- Indexes for table `kitchen`
--
ALTER TABLE `kitchen`
  ADD PRIMARY KEY (`itemID`);

--
-- Indexes for table `livingroom`
--
ALTER TABLE `livingroom`
  ADD PRIMARY KEY (`itemID`);

--
-- Indexes for table `office`
--
ALTER TABLE `office`
  ADD PRIMARY KEY (`itemID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `bathroom`
--
ALTER TABLE `bathroom`
  MODIFY `itemID` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `bedroom`
--
ALTER TABLE `bedroom`
  MODIFY `itemID` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `kitchen`
--
ALTER TABLE `kitchen`
  MODIFY `itemID` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;

--
-- AUTO_INCREMENT for table `livingroom`
--
ALTER TABLE `livingroom`
  MODIFY `itemID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- AUTO_INCREMENT for table `office`
--
ALTER TABLE `office`
  MODIFY `itemID` int(8) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
