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
}
