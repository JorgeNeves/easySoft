using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

namespace SocialiteWebService
{
    [ServiceContract]
    public interface SocialiteOperations
    {
        [OperationContract]
        String Login(string username, string password);

        [OperationContract]
        String Logout(string token);

        [OperationContract]
        ServiceStatus Status();

        [OperationContract]
        UserData GetUserData(int userid, string token);

        [OperationContract]
        string GetWord();
    }

    [DataContract]
    public class ServiceStatus
    {
        [DataMember(Order = 1)]
        public string Status { get; set; }
        [DataMember(Order = 2)]
        public int TotalUsers { get; set; }
        [DataMember(Order = 3)]
        public int OnlineUsers { get; set; }
    }

    [DataContract]
    public class UserData
    {
        [DataMember(Order = 1)]
        public int UserID { get; set; }

        [DataMember(Order = 2)]
        public string UserName { get; set; }

        [DataMember(Order = 3)]
        public string UserMood { get; set; }

        [DataMember(Order = 4)]
        public List<string> Usertags { get; set; }
        [DataMember(Order = 5)]
        public List<int> UserFriendsIDs { get; set; }
    }
    
    [DataContract]
    public class Relationship
    {
        public int RelID { get; set; }
        public int FriendID { get; set; }
        public List<string> RelTags { get; set; }
    }
}
