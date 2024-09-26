-- MySQL dump 10.13  Distrib 8.0.38, for Win64 (x86_64)
--
-- Host: localhost    Database: hobusetall
-- ------------------------------------------------------
-- Server version	8.0.39

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `breed`
--

DROP TABLE IF EXISTS `breed`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `breed` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  `Breed` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `breed`
--

LOCK TABLES `breed` WRITE;
/*!40000 ALTER TABLE `breed` DISABLE KEYS */;
/*!40000 ALTER TABLE `breed` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employees`
--

DROP TABLE IF EXISTS `employees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employees` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  `Phone` bigint unsigned NOT NULL,
  `Shift` datetime NOT NULL,
  `PremissionLevel` bigint unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `employees_premissionlevel_foreign` (`PremissionLevel`),
  CONSTRAINT `employees_premissionlevel_foreign` FOREIGN KEY (`PremissionLevel`) REFERENCES `premissions` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employees`
--

LOCK TABLES `employees` WRITE;
/*!40000 ALTER TABLE `employees` DISABLE KEYS */;
/*!40000 ALTER TABLE `employees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `equipment`
--

DROP TABLE IF EXISTS `equipment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `equipment` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `EquipmentType` varchar(255) NOT NULL,
  `Stable` bigint unsigned NOT NULL,
  `Amount` bigint unsigned NOT NULL,
  `Price` bigint unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `equipment_stable_foreign` (`Stable`),
  CONSTRAINT `equipment_stable_foreign` FOREIGN KEY (`Stable`) REFERENCES `stable` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `equipment`
--

LOCK TABLES `equipment` WRITE;
/*!40000 ALTER TABLE `equipment` DISABLE KEYS */;
/*!40000 ALTER TABLE `equipment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `health`
--

DROP TABLE IF EXISTS `health`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `health` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  `Health` varchar(255) NOT NULL,
  `Veterinary procedures` varchar(255) NOT NULL,
  `ProcedureDate` date NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `health`
--

LOCK TABLES `health` WRITE;
/*!40000 ALTER TABLE `health` DISABLE KEYS */;
/*!40000 ALTER TABLE `health` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `horse`
--

DROP TABLE IF EXISTS `horse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `horse` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  `Birthdate` date NOT NULL,
  `Owners` bigint unsigned NOT NULL,
  `Stables` bigint unsigned NOT NULL,
  `Breeds` bigint unsigned NOT NULL,
  `Health` bigint unsigned NOT NULL,
  `Training` bigint unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `horse_stables_foreign` (`Stables`),
  KEY `horse_owners_foreign` (`Owners`),
  KEY `horse_health_foreign` (`Health`),
  KEY `horse_training_foreign` (`Training`),
  KEY `horse_breeds_foreign` (`Breeds`),
  CONSTRAINT `horse_breeds_foreign` FOREIGN KEY (`Breeds`) REFERENCES `breed` (`id`),
  CONSTRAINT `horse_health_foreign` FOREIGN KEY (`Health`) REFERENCES `health` (`id`),
  CONSTRAINT `horse_owners_foreign` FOREIGN KEY (`Owners`) REFERENCES `owner` (`id`),
  CONSTRAINT `horse_stables_foreign` FOREIGN KEY (`Stables`) REFERENCES `stable` (`id`),
  CONSTRAINT `horse_training_foreign` FOREIGN KEY (`Training`) REFERENCES `training schedules` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `horse`
--

LOCK TABLES `horse` WRITE;
/*!40000 ALTER TABLE `horse` DISABLE KEYS */;
/*!40000 ALTER TABLE `horse` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `owner`
--

DROP TABLE IF EXISTS `owner`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `owner` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  `Phone` bigint unsigned NOT NULL,
  `Address` varchar(255) NOT NULL,
  `Account` varchar(255) NOT NULL,
  `PremissionLevel` bigint unsigned NOT NULL,
  `Shift` datetime NOT NULL,
  PRIMARY KEY (`id`),
  KEY `owner_premissionlevel_foreign` (`PremissionLevel`),
  CONSTRAINT `owner_premissionlevel_foreign` FOREIGN KEY (`PremissionLevel`) REFERENCES `premissions` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `owner`
--

LOCK TABLES `owner` WRITE;
/*!40000 ALTER TABLE `owner` DISABLE KEYS */;
/*!40000 ALTER TABLE `owner` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `premissions`
--

DROP TABLE IF EXISTS `premissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `premissions` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Level` bigint unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `premissions`
--

LOCK TABLES `premissions` WRITE;
/*!40000 ALTER TABLE `premissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `premissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stable`
--

DROP TABLE IF EXISTS `stable`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `stable` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Address` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stable`
--

LOCK TABLES `stable` WRITE;
/*!40000 ALTER TABLE `stable` DISABLE KEYS */;
/*!40000 ALTER TABLE `stable` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `training schedules`
--

DROP TABLE IF EXISTS `training schedules`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `training schedules` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `Horse name` varchar(255) NOT NULL,
  `ShiftTime` datetime NOT NULL,
  `Employee` bigint unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `training schedules_employee_foreign` (`Employee`),
  CONSTRAINT `training schedules_employee_foreign` FOREIGN KEY (`Employee`) REFERENCES `employees` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `training schedules`
--

LOCK TABLES `training schedules` WRITE;
/*!40000 ALTER TABLE `training schedules` DISABLE KEYS */;
/*!40000 ALTER TABLE `training schedules` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-09-26 11:41:27
